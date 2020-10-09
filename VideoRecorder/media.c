//
//  media.c
//  VideoRecorder
//
//  Created by 马良 on 2020/10/9.
//

#include "media.h"

static int rec_status = 0;

void set_status(int status) {
  rec_status = status;
}

void open_media() {
  AVFormatContext *fmt_ctx = NULL;
  AVDictionary *options = NULL;

  int ret = 0;
  char errors[1024] = {0,};
  char *device_name = ":0";

  int count = 0;
  AVPacket *pkt = NULL;

  av_log_set_level(AV_LOG_DEBUG);
  set_status(1);
  avdevice_register_all();

  AVInputFormat *format = av_find_input_format("avfoundation");

  if ((ret = avformat_open_input(&fmt_ctx, device_name, format, &options)) < 0) {
    av_strerror(ret, errors, 1024);
    av_log(NULL, AV_LOG_ERROR, "failed to open audio device: %s", errors);
    return;
  }

  av_log(NULL, AV_LOG_DEBUG, "open device ok\n");

  char *out = "audio.pcm";
  FILE *out_file = fopen(out, "wb+");

  pkt = av_packet_alloc();

  while ((ret = av_read_frame(fmt_ctx, pkt)) == 0 && rec_status) {
    fwrite(pkt->data, (size_t) pkt->size, 1, out_file);
    fflush(out_file);
    av_log(NULL, AV_LOG_INFO, "pkt size: %d, data: %p, count: %d\n", pkt->size, &pkt->data, count);
    av_packet_unref(pkt);
  }

  fclose(out_file);

  avformat_close_input(&fmt_ctx);

  avformat_free_context(fmt_ctx);

  av_log(NULL, AV_LOG_DEBUG, "done\n");
  return;
}
