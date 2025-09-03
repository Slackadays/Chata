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

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/opt.h>
#include <libavutil/samplefmt.h>
}

namespace fs = std::filesystem;

bool assemble_flag = false;
bool no_write_flag = false;
bool silent_flag = false;
std::string input_data_file;

#if defined(__linux__) || defined(__unix__) || defined(__APPLE__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__HAIKU__) || defined(__FreeBSD__) \
        || defined(__posix__)
#define UNIX_OR_UNIX_LIKE
#endif

size_t writeToFile(const fs::path& path, const std::string& content, bool append = false) {
    std::ofstream file(path, append ? std::ios::app : std::ios::trunc | std::ios::binary);
    file << content;
    return content.size();
}

std::optional<std::string> fileContents(const fs::path& path) {
#if defined(UNIX_OR_UNIX_LIKE)
    errno = 0;
    int fd = open(path.string().data(), O_RDONLY);
    if (fd == -1) {
        if (errno == ENOENT)
            return std::nullopt;
        else
            throw std::runtime_error("Couldn't open file " + path.string() + ": " + std::strerror(errno));
    }
    std::string contents;
#if defined(__linux__) || defined(__FreeBSD__)
    std::array<char, 65536> buffer;
#elif defined(__APPLE__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
    std::array<char, 16384> buffer;
#else
    std::array<char, PIPE_BUF> buffer;
#endif
    ssize_t bytes_read;
    errno = 0;
    while ((bytes_read = read(fd, buffer.data(), buffer.size())) > 0) {
        contents.append(buffer.data(), bytes_read);
        if (bytes_read < buffer.size() && errno == 0) break; // check if we reached EOF early and not due to an error
    }
    close(fd);
    return contents;
#else
    std::stringstream buffer;
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) return std::nullopt;
    buffer << file.rdbuf();
    return buffer.str();
#endif
}

int main(int argc, char* argv[]) {
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
                std::cout << "You must provide a filename after -i" << std::endl;
                return 1;
            }
        }
    }

    if (!silent_flag) {
        std::cout << "Welcome to ChataCLI " << PROJECT_VERSION << " (commit " << GIT_COMMIT_HASH << " on branch " << GIT_BRANCH << ")" << std::endl;
        std::cout << "libchata version: " << libchata::version() << std::endl;
    }
    if (argc < 2) {
        std::cout << "You must provide one or more files" << std::endl;
        return 1;
    }

    if (!input_data_file.empty()) {
        std::vector<std::vector<double>> raw_sample_data;

        AVFormatContext* format_context = nullptr;

        if (avformat_open_input(&format_context, input_data_file.c_str(), nullptr, nullptr) != 0) {
            std::cout << "Could not open input file: " << input_data_file << std::endl;
            return 1;
        }

        if (avformat_find_stream_info(format_context, nullptr) < 0) {
            std::cout << "Could not find stream information in file: " << input_data_file << std::endl;
            avformat_close_input(&format_context);
            return 1;
        }

        int audio_stream_index = -1;
        const AVCodec* codec = nullptr;
        AVCodecParameters* codec_params = nullptr;

        for (unsigned int i = 0; i < format_context->nb_streams; ++i) {
            if (format_context->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO) {
                audio_stream_index = i;
                codec_params = format_context->streams[i]->codecpar;
                codec = avcodec_find_decoder(codec_params->codec_id);
                if (!codec) {
                    avformat_close_input(&format_context);
                    std::cout << "Unsupported codec in file: " << input_data_file << std::endl;
                    return 1;
                }
                break;
            }
        }

        if (audio_stream_index == -1) {
            std::cout << "No audio stream found in file: " << input_data_file << std::endl;
            avformat_close_input(&format_context);
            return 1;
        }

        if (!silent_flag) {
            std::cout << "Audio stream found in file: " << input_data_file << std::endl;
        }

        if (!input_data_file.empty()) {
            std::vector<std::vector<double>> raw_sample_data;

            AVFormatContext* format_context = nullptr;

            if (avformat_open_input(&format_context, input_data_file.c_str(), nullptr, nullptr) != 0) {
                std::cout << "Could not open input file: " << input_data_file << std::endl;
                return 1;
            }

            if (avformat_find_stream_info(format_context, nullptr) < 0) {
                std::cout << "Could not find stream information in file: " << input_data_file << std::endl;
                avformat_close_input(&format_context);
                return 1;
            }

            int audio_stream_index = -1;
            const AVCodec* codec = nullptr;
            AVCodecParameters* codec_params = nullptr;

            for (unsigned int i = 0; i < format_context->nb_streams; ++i) {
                if (format_context->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO) {
                    audio_stream_index = i;
                    codec_params = format_context->streams[i]->codecpar;
                    codec = avcodec_find_decoder(codec_params->codec_id);
                    if (!codec) {
                        avformat_close_input(&format_context);
                        std::cout << "Unsupported codec in file: " << input_data_file << std::endl;
                        return 1;
                    }
                    break;
                }
            }

            if (audio_stream_index == -1) {
                std::cout << "No audio stream found in file: " << input_data_file << std::endl;
                avformat_close_input(&format_context);
                return 1;
            }

            if (!silent_flag) {
                std::cout << "Audio stream found in file: " << input_data_file << std::endl;
            }

            AVCodecContext* codec_context = avcodec_alloc_context3(codec);

            if (!codec_context) {
                avformat_close_input(&format_context);
                std::cout << "Could not allocate codec context" << std::endl;
                return 1;
            }

            if (avcodec_parameters_to_context(codec_context, codec_params) < 0) {
                avcodec_free_context(&codec_context);
                avformat_close_input(&format_context);
                std::cout << "Could not copy codec parameters to codec context" << std::endl;
                return 1;
            }

            if (avcodec_open2(codec_context, codec, nullptr) < 0) {
                avcodec_free_context(&codec_context);
                avformat_close_input(&format_context);
                std::cout << "Could not open codec" << std::endl;
                return 1;
            }

            AVPacket* packet = av_packet_alloc();
            if (!packet) {
                std::cout << "Could not allocate packet" << std::endl;
                avcodec_free_context(&codec_context);
                avformat_close_input(&format_context);
                return 1;
            }

            AVFrame* frame = av_frame_alloc();
            if (!frame) {
                std::cout << "Could not allocate frame" << std::endl;
                av_packet_free(&packet);
                avcodec_free_context(&codec_context);
                avformat_close_input(&format_context);
                return 1;
            }

            AVSampleFormat sample_fmt = codec_context->sample_fmt;
            bool is_planar = av_sample_fmt_is_planar(sample_fmt);
            int channels = av_get_channel_layout_nb_channels(codec_context->channel_layout);
            int bytes_per_sample = av_get_bytes_per_sample(sample_fmt);

            if (!(sample_fmt == AV_SAMPLE_FMT_S16 || sample_fmt == AV_SAMPLE_FMT_S16P || sample_fmt == AV_SAMPLE_FMT_S32 || sample_fmt == AV_SAMPLE_FMT_S32P || sample_fmt == AV_SAMPLE_FMT_FLT
                  || sample_fmt == AV_SAMPLE_FMT_FLTP || sample_fmt == AV_SAMPLE_FMT_DBL || sample_fmt == AV_SAMPLE_FMT_DBLP)) {
                std::cout << "Unsupported sample format" << std::endl;
                av_frame_free(&frame);
                av_packet_free(&packet);
                avcodec_free_context(&codec_context);
                avformat_close_input(&format_context);
                return 1;
            }

            raw_sample_data.resize(channels);

            auto process_frame = [&]() -> int {
                int nb_samples = frame->nb_samples;
                size_t current_samples = raw_sample_data[0].size();

                for (auto& ch_data : raw_sample_data) {
                    ch_data.resize(current_samples + nb_samples);
                }

                if (is_planar) {
                    for (int ch = 0; ch < channels; ++ch) {
                        double* dest = raw_sample_data[ch].data() + current_samples;
                        uint8_t* src = frame->data[ch];
                        if (sample_fmt == AV_SAMPLE_FMT_FLTP) {
                            float* fsrc = reinterpret_cast<float*>(src);
                            for (int i = 0; i < nb_samples; ++i) {
                                dest[i] = static_cast<double>(fsrc[i]);
                            }
                        } else if (sample_fmt == AV_SAMPLE_FMT_DBLP) {
                            double* dsrc = reinterpret_cast<double*>(src);
                            for (int i = 0; i < nb_samples; ++i) {
                                dest[i] = dsrc[i];
                            }
                        } else if (sample_fmt == AV_SAMPLE_FMT_S16P) {
                            int16_t* isrc = reinterpret_cast<int16_t*>(src);
                            for (int i = 0; i < nb_samples; ++i) {
                                dest[i] = isrc[i] / 32768.0;
                            }
                        } else if (sample_fmt == AV_SAMPLE_FMT_S32P) {
                            int32_t* isrc = reinterpret_cast<int32_t*>(src);
                            for (int i = 0; i < nb_samples; ++i) {
                                dest[i] = isrc[i] / 2147483648.0;
                            }
                        }
                    }
                } else {
                    uint8_t* src = frame->data[0];
                    for (int i = 0; i < nb_samples; ++i) {
                        uint8_t* sample_ptr = src + i * channels * bytes_per_sample;
                        for (int ch = 0; ch < channels; ++ch) {
                            uint8_t* ch_ptr = sample_ptr + ch * bytes_per_sample;
                            double* dest = &raw_sample_data[ch][current_samples + i];
                            if (sample_fmt == AV_SAMPLE_FMT_FLT) {
                                *dest = static_cast<double>(*reinterpret_cast<float*>(ch_ptr));
                            } else if (sample_fmt == AV_SAMPLE_FMT_DBL) {
                                *dest = *reinterpret_cast<double*>(ch_ptr);
                            } else if (sample_fmt == AV_SAMPLE_FMT_S16) {
                                *dest = *reinterpret_cast<int16_t*>(ch_ptr) / 32768.0;
                            } else if (sample_fmt == AV_SAMPLE_FMT_S32) {
                                *dest = *reinterpret_cast<int32_t*>(ch_ptr) / 2147483648.0;
                            }
                        }
                    }
                }
                return 0;
            };

            while (av_read_frame(format_context, packet) >= 0) {
                if (packet->stream_index != audio_stream_index) {
                    av_packet_unref(packet);
                    continue;
                }

                int ret = avcodec_send_packet(codec_context, packet);
                if (ret < 0) {
                    std::cout << "Error sending packet to decoder" << std::endl;
                    av_packet_unref(packet);
                    av_frame_free(&frame);
                    av_packet_free(&packet);
                    avcodec_free_context(&codec_context);
                    avformat_close_input(&format_context);
                    return 1;
                }

                while (true) {
                    ret = avcodec_receive_frame(codec_context, frame);
                    if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF) {
                        break;
                    }
                    if (ret < 0) {
                        std::cout << "Error receiving frame from decoder" << std::endl;
                        av_packet_unref(packet);
                        av_frame_free(&frame);
                        av_packet_free(&packet);
                        avcodec_free_context(&codec_context);
                        avformat_close_input(&format_context);
                        return 1;
                    }

                    if (process_frame() != 0) {
                        av_packet_unref(packet);
                        av_frame_free(&frame);
                        av_packet_free(&packet);
                        avcodec_free_context(&codec_context);
                        avformat_close_input(&format_context);
                        return 1;
                    }
                }

                av_packet_unref(packet);
            }

            int ret = avcodec_send_packet(codec_context, nullptr);
            if (ret < 0) {
                std::cout << "Error sending flush packet to decoder" << std::endl;
                av_frame_free(&frame);
                av_packet_free(&packet);
                avcodec_free_context(&codec_context);
                avformat_close_input(&format_context);
                return 1;
            }

            while (true) {
                ret = avcodec_receive_frame(codec_context, frame);
                if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF) {
                    break;
                }
                if (ret < 0) {
                    std::cout << "Error receiving frame during flush" << std::endl;
                    av_frame_free(&frame);
                    av_packet_free(&packet);
                    avcodec_free_context(&codec_context);
                    avformat_close_input(&format_context);
                    return 1;
                }

                if (process_frame() != 0) {
                    av_frame_free(&frame);
                    av_packet_free(&packet);
                    avcodec_free_context(&codec_context);
                    avformat_close_input(&format_context);
                    return 1;
                }
            }

            av_frame_free(&frame);
            av_packet_free(&packet);
            avcodec_free_context(&codec_context);
            avformat_close_input(&format_context);

            if (!silent_flag) {
                std::cout << "Audio data extracted successfully from: " << input_data_file << std::endl;
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
}