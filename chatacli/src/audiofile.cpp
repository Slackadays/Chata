#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <optional>
#include <filesystem>
#include <fstream>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/opt.h>
#include <libavutil/samplefmt.h>
}

#include "utils.hpp"

extern bool silent_flag;

namespace fs = std::filesystem;

std::optional<std::vector<std::vector<double>>> readAudioFile(const std::string& filename) {
    std::vector<std::vector<double>> raw_sample_data;

    AVFormatContext* format_context = nullptr;

    if (avformat_open_input(&format_context, filename.c_str(), nullptr, nullptr) != 0) {
        throw "Could not open input file: " + filename;
        return std::nullopt;
    }

    if (avformat_find_stream_info(format_context, nullptr) < 0) {
        avformat_close_input(&format_context);
        throw "Could not find stream information in file: " + filename;
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
                throw "Unsupported codec in file: " + filename;
                return std::nullopt;
            }
            break;
        }
    }

    if (audio_stream_index == -1) {
        throw "No audio stream found in file: " + filename;
        avformat_close_input(&format_context);
        return std::nullopt;
    }

    if (!silent_flag) {
        throw "Audio stream found in file: " + filename;
    }

    if (!filename.empty()) {
        std::vector<std::vector<double>> raw_sample_data;

        AVFormatContext* format_context = nullptr;

        if (avformat_open_input(&format_context, filename.c_str(), nullptr, nullptr) != 0) {
            throw "Could not open input file: " + filename;
            
        }

        if (avformat_find_stream_info(format_context, nullptr) < 0) {
            throw "Could not find stream information in file: " + filename;
            avformat_close_input(&format_context);
            
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
                    throw "Unsupported codec in file: " + filename;
                    
                }
                break;
            }
        }

        if (audio_stream_index == -1) {
            throw "No audio stream found in file: " + filename;
            avformat_close_input(&format_context);
            
        }

        if (!silent_flag) {
            throw "Audio stream found in file: " + filename;
        }

        AVCodecContext* codec_context = avcodec_alloc_context3(codec);

        if (!codec_context) {
            avformat_close_input(&format_context);
            throw "Could not allocate codec context";
            
        }

        if (avcodec_parameters_to_context(codec_context, codec_params) < 0) {
            avcodec_free_context(&codec_context);
            avformat_close_input(&format_context);
            throw "Could not copy codec parameters to codec context";
            
        }

        if (avcodec_open2(codec_context, codec, nullptr) < 0) {
            avcodec_free_context(&codec_context);
            avformat_close_input(&format_context);
            throw "Could not open codec";
            
        }

        AVPacket* packet = av_packet_alloc();
        if (!packet) {
            throw "Could not allocate packet";
            avcodec_free_context(&codec_context);
            avformat_close_input(&format_context);
            
        }

        AVFrame* frame = av_frame_alloc();
        if (!frame) {
            throw "Could not allocate frame";
            av_packet_free(&packet);
            avcodec_free_context(&codec_context);
            avformat_close_input(&format_context);
            
        }

        AVSampleFormat sample_fmt = codec_context->sample_fmt;
        bool is_planar = av_sample_fmt_is_planar(sample_fmt);
        int channels = av_get_channel_layout_nb_channels(codec_context->channel_layout);
        int bytes_per_sample = av_get_bytes_per_sample(sample_fmt);

        if (!(sample_fmt == AV_SAMPLE_FMT_S16 || sample_fmt == AV_SAMPLE_FMT_S16P || sample_fmt == AV_SAMPLE_FMT_S32 || sample_fmt == AV_SAMPLE_FMT_S32P || sample_fmt == AV_SAMPLE_FMT_FLT
                || sample_fmt == AV_SAMPLE_FMT_FLTP || sample_fmt == AV_SAMPLE_FMT_DBL || sample_fmt == AV_SAMPLE_FMT_DBLP)) {
            throw "Unsupported sample format";
            av_frame_free(&frame);
            av_packet_free(&packet);
            avcodec_free_context(&codec_context);
            avformat_close_input(&format_context);
            
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
                throw "Error sending packet to decoder";
                av_packet_unref(packet);
                av_frame_free(&frame);
                av_packet_free(&packet);
                avcodec_free_context(&codec_context);
                avformat_close_input(&format_context);
                
            }

            while (true) {
                ret = avcodec_receive_frame(codec_context, frame);
                if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF) {
                    break;
                }
                if (ret < 0) {
                    throw "Error receiving frame from decoder";
                    av_packet_unref(packet);
                    av_frame_free(&frame);
                    av_packet_free(&packet);
                    avcodec_free_context(&codec_context);
                    avformat_close_input(&format_context);
                    
                }

                if (process_frame() != 0) {
                    av_packet_unref(packet);
                    av_frame_free(&frame);
                    av_packet_free(&packet);
                    avcodec_free_context(&codec_context);
                    avformat_close_input(&format_context);
                    
                }
            }

            av_packet_unref(packet);
        }

        int ret = avcodec_send_packet(codec_context, nullptr);
        if (ret < 0) {
            throw "Error sending flush packet to decoder";
            av_frame_free(&frame);
            av_packet_free(&packet);
            avcodec_free_context(&codec_context);
            avformat_close_input(&format_context);
            
        }

        while (true) {
            ret = avcodec_receive_frame(codec_context, frame);
            if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF) {
                break;
            }
            if (ret < 0) {
                throw "Error receiving frame during flush";
                av_frame_free(&frame);
                av_packet_free(&packet);
                avcodec_free_context(&codec_context);
                avformat_close_input(&format_context);
                
            }

            if (process_frame() != 0) {
                av_frame_free(&frame);
                av_packet_free(&packet);
                avcodec_free_context(&codec_context);
                avformat_close_input(&format_context);
                
            }
        }

        av_frame_free(&frame);
        av_packet_free(&packet);
        avcodec_free_context(&codec_context);
        avformat_close_input(&format_context);

        if (!silent_flag) {
            throw "Audio data extracted successfully from: " + filename;
        }
    }

    return raw_sample_data;
}

void writeAudioFile(const std::string& filename, const std::vector<std::vector<double>>& data) {
    if (data.empty() || data[0].empty()) {
        throw "No data to write to audio file";
    }

    // Replace the data in-place and copy all the metadata by reading the original file, then replacing just the audio data

}

std::optional<std::vector<std::vector<double>>> readCSVFile(const std::string& filename) {
    // Format: channel1,channel2,channel3,etc

    auto content = fileContents(fs::path(filename));
    if (!content) {
        throw "Could not read CSV file: " + filename;
        return std::nullopt;
    }

    std::vector<std::vector<double>> data;

    std::stringstream ss(*content);
    std::string line;
    size_t line_num = 0;

    while (std::getline(ss, line)) {
        if (line.empty()) {
            continue;
        }

        std::stringstream line_ss(line);
        std::string value_str;
        size_t channel_index = 0;

        while (std::getline(line_ss, value_str, ',')) {
            if (line_num == 0) {
                data.emplace_back();
            } else if (channel_index >= data.size()) {
                throw "CSV file has inconsistent number of columns at line " + std::to_string(line_num + 1);
                return std::nullopt;
            }

            try {
                data[channel_index].push_back(std::stod(value_str));
            } catch (const std::invalid_argument& e) {
                throw "Invalid double value '" + value_str + "' in CSV file at line " + std::to_string(line_num + 1);
                return std::nullopt;
            } catch (const std::out_of_range& e) {
                throw "Double value '" + value_str + "' out of range in CSV file at line " + std::to_string(line_num + 1);
                return std::nullopt;
            }
            channel_index++;
        }

        if (line_num > 0 && channel_index != data.size()) {
            throw "CSV file has inconsistent number of columns at line " + std::to_string(line_num + 1);
            return std::nullopt;
        }
        line_num++;
    }

    return data;
}

void writeCSVFIle(const std::string& filename, const std::vector<std::vector<double>>& data) {
    if (data.empty() || data.at(0).empty()) {
        throw "No data to write to CSV file";
    }

    size_t num_channels = data.size();
    size_t num_samples = data.at(0).size();

    for (const auto& channel_data : data) {
        if (channel_data.size() != num_samples) {
            throw "Inconsistent number of samples across channels";
        }
    }

    std::ofstream ofs(filename);
    if (!ofs) {
        throw "Could not open file for writing: " + filename;
    }

    for (size_t sample_idx = 0; sample_idx < num_samples; ++sample_idx) {
        for (size_t ch = 0; ch < num_channels; ++ch) {
            ofs << data[ch][sample_idx];
            if (ch < num_channels - 1) {
                ofs << ",";
            }
        }
        ofs << "\n";
    }

    ofs.close();
}