//
// Created by px on 7/9/2019.
//

#ifndef MODEL_TEST_EDITABLEVIDEO_H
#define MODEL_TEST_EDITABLEVIDEO_H

#include "./Model.h"

class EditableVideo{
private:
    int64_t duration;
    int64_t currentTime;
    bool playing;
public:
    EditableVideo(std::string srcPath);

};

EditableVideo::EditableVideo(std::string srcPath) {
    AVFormatContext *pFormatContext = avformat_alloc_context();
    if (!pFormatContext) {
        printf("ERROR could not allocate memory for Format Context");
        exit(1);
    }
    if (avformat_open_input(&pFormatContext, srcPath.c_str(), nullptr, nullptr) != 0) {
        printf("ERROR could not open the file");
        exit(1);
    }
    this->duration = pFormatContext->duration;
    this->currentTime = 0;
    this->playing = false;
    printf("format %s, duration %lld us, bit_rate %lld", pFormatContext->iformat->name, pFormatContext->duration, pFormatContext->bit_rate);
    if (avformat_find_stream_info(pFormatContext,  nullptr) < 0) {
        printf("ERROR could not get the stream info");
        exit(1);
    }
    AVCodec *pCodec = nullptr;
    AVCodecParameters *pCodecParameters =  nullptr;
    int video_stream_index = -1;
    for (int i = 0; i < pFormatContext->nb_streams; i++){
        AVCodecParameters *pLocalCodecParameters =  nullptr;
        pLocalCodecParameters = pFormatContext->streams[i]->codecpar;

        AVCodec *pLocalCodec = nullptr;

        // finds the registered decoder for a codec ID

        pLocalCodec = avcodec_find_decoder(pLocalCodecParameters->codec_id);

        if (pLocalCodec==nullptr) {
            printf("ERROR unsupported codec!");
            exit(1);
        }

        // when the stream is a video we store its index, codec parameters and codec
        if (pLocalCodecParameters->codec_type == AVMEDIA_TYPE_AUDIO) {
            printf("Audio Codec: %d channels, sample rate %d", pLocalCodecParameters->channels, pLocalCodecParameters->sample_rate);
        }

        // print its name, id and bitrate
        printf("\tCodec %s ID %d bit_rate %lld", pLocalCodec->name, pLocalCodec->id, pCodecParameters->bit_rate);
    }
}

#endif //MODEL_TEST_EDITABLEVIDEO_H
