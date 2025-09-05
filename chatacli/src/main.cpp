// SPDX-License-Identifier: MPL-2.0
#include <array>
#include <chrono>
#include <cstring>
#include <fcntl.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <libchata.hpp>
#include <optional>
#include <string>
#include <thread>
#include <ultrassembler.hpp>
#include <unistd.h>
#include <vector>

#include "audiofile.hpp"
#include "utils.hpp"

namespace fs = std::filesystem;

bool assemble_flag = false;
bool no_write_flag = false;
bool silent_flag = false;
std::string input_data_file;

int input_file_mode = 0; // 0 = default, 1 = audio file, 2 = CSV

size_t writeToFile(const fs::path& path, const std::string& content, bool append = false) {
    std::ofstream file(path, append ? std::ios::app : std::ios::trunc | std::ios::binary);
    file << content;
    return content.size();
}

int main(int argc, char* argv[]) {
    try {
        std::vector<std::string> args;
        for (int i = 0; i < argc; i++) {
            args.push_back(argv[i]);
        }

        for (size_t i = 0; i < args.size(); i++) {
            if (args.at(i) == "-a") {
                assemble_flag = true;
                args.erase(args.begin() + i);
            }
            if (args.at(i) == "--no-write") {
                no_write_flag = true;
                args.erase(args.begin() + i);
            }
            if (args.at(i) == "--silent") {
                silent_flag = true;
                args.erase(args.begin() + i);
            }
            if (args.at(i) == "-i") {
                if (i + 1 < args.size()) {
                    input_data_file = args.at(i + 1);
                    args.erase(args.begin() + i);
                    args.erase(args.begin() + i);
                } else {
                    throw "You must provide a filename after -i";
                }
            }
        }

        if (!silent_flag) {
            std::cout << "Welcome to ChataCLI " << PROJECT_VERSION << " (commit " << GIT_COMMIT_HASH << " on branch " << GIT_BRANCH << ")" << std::endl;
            std::cout << "libchata version: " << libchata::version() << std::endl;
        }
        if (argc < 2) {
            throw "You must provide one or more files";
        }

        if (!input_data_file.empty()) {
            auto data = readAudioFile(input_data_file);
            if (data.has_value()) {
                if (!silent_flag) {
                    std::cout << "Read " << data->size() << " channels from audio file " << input_data_file << std::endl;
                }
                input_file_mode = 1;
            } else {
                std::cout << "Failed to read audio file " << input_data_file << ", switching to CSV mode" << std::endl;

                data = readCSVFile(input_data_file);
                if (!data.has_value()) {
                    throw "Failed to read CSV file " + input_data_file;
                } else {
                    if (!silent_flag) {
                        std::cout << "Read " << data->size() << " channels from CSV file " << input_data_file << std::endl;
                    }
                    input_file_mode = 2;
                }
            }

            ChataProcessor processor;

            try {
                fs::path filePath = args.back();
                auto contents = fileContents(filePath);

                if (!contents) {
                    throw "File not found: " + filePath.string();
                }

                if (!silent_flag) {
                    std::cout << "File found: " << filePath.string() << std::endl;
                }

                InputFile file(*contents, filePath.string());

                processor.compile_and_commit(file);

                if (!silent_flag) {
                    std::cout << "Processing " << data->at(0).size() << " samples per channel" << std::endl;
                }

                chata_args args;

                for (size_t i = 0; i < data->at(0).size(); i++) {
                    for (size_t ch = 0; ch < data->size(); ch++) {
                        if (ch == 0) {
                            args.input1 = data->at(ch).at(i);
                        } else if (ch == 1) {
                            args.input2 = data->at(ch).at(i);
                        } else if (ch == 2) {
                            args.input3 = data->at(ch).at(i);
                        } else if (ch == 3) {
                            args.input4 = data->at(ch).at(i);
                        } else if (ch == 4) {
                            args.input5 = data->at(ch).at(i);
                        } else if (ch == 5) {
                            args.input6 = data->at(ch).at(i);
                        }
                    }

                    processor.process_data(args);

                    for (size_t ch = 0; ch < data->size(); ch++) {
                        if (ch == 0) {
                            data->at(ch).at(i) = args.input1;
                        } else if (ch == 1) {
                            data->at(ch).at(i) = args.input2;
                        } else if (ch == 2) {
                            data->at(ch).at(i) = args.input3;
                        } else if (ch == 3) {
                            data->at(ch).at(i) = args.input4;
                        } else if (ch == 4) {
                            data->at(ch).at(i) = args.input5;
                        } else if (ch == 5) {
                            data->at(ch).at(i) = args.input6;
                        }
                    }
                }

            } catch (ChataError& e) {
                std::cout << e.what() << std::endl;
                return 1;
            }

            if (input_file_mode == 1) {
                if (!silent_flag) {
                    std::cout << "Success!" << std::endl;
                    std::cout << "Writing modified audio data back to " << input_data_file << std::endl;
                }
            } else if (input_file_mode == 2) {
                if (!silent_flag) {
                    std::cout << "Success!" << std::endl;
                    std::cout << "Writing modified CSV data back to " << input_data_file << std::endl;
                }


            }
        }

        fs::path filePath = args.back();
        auto contents = fileContents(filePath);

        if (!silent_flag) {
            if (contents) {
                std::cout << "File found: " << filePath.string() << std::endl;
            } else {
                std::cout << "File not found: " << filePath.string() << std::endl;
                return 1;
            }
        }

        InputFile file(*contents, filePath.string());

        if (assemble_flag) {
            std::span<uint8_t> result;
            try {
                result = ultrassembler::assemble(file.data);
            } catch (ChataError& e) {
                std::cout << e.what() << std::endl;
                return 1;
            } catch (UASError& e) {
                std::cout << "" << e.what() << std::endl;
                return 1;
            }
            if (!no_write_flag) {
                std::string filename = filePath.replace_extension(".bin").string();
                if (!silent_flag) {
                    std::cout << "Writing result to " << filename << std::endl;
                }

                writeToFile(filename, std::string(result.begin(), result.end()));
            } else {
                if (!silent_flag) {
                    std::cout << "Skipping writing the result to a file" << std::endl;
                }
            }
            return 0;
        }

        if (!silent_flag) {
            std::cout << "Processing the file " << filePath.string() << std::endl;
        }

        ChataProcessor processor;

        try {
            processor.compile_and_commit(file);

            double value = 2.0;

            if (!silent_flag) {
                std::cout << "Ok, let's see if we can change the value of a float. Current value: " << value << std::endl;
            }

            chata_args args;

            args.input1 = value;

            processor.process_data(args);

            if (!silent_flag) {
                std::cout << "New value: " << args.input1 << std::endl;
            }

        } catch (ChataError& e) {
            std::cout << "" << e.what() << std::endl;
            return 1;
        }

        if (!silent_flag) {
            std::cout << "Success!" << std::endl;
        }
    } catch (const char* msg) {
        std::cout << "Error: " << msg << std::endl;
        return 1;
    } catch (std::string& msg) {
        std::cout << "Error: " << msg << std::endl;
        return 1;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
}