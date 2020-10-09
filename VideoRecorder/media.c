//
//  media.c
//  VideoRecorder
//
//  Created by 马良 on 2020/10/9.
//

#include "media.h"

void open_media() {
  AVFormatContext *fmt_ctx = NULL;
  AVDictionary *options = NULL;

  int ret = 0;
  char errors[1024];
  char *device_name = ":1";

  av_log_set_level(AV_LOG_DEBUG);
  avdevice_register_all();
  AVInputFormat *format = av_find_input_format("avfoundation");
  ret = avformat_open_input(&fmt_ctx,
                            device_name,
                            format,
                            &options);

  if (ret < 0) {
    av_strerror(ret, errors, 1024);
    printf((const char *) stderr, "failed to open audio device: %s", errors);
    return;
  }

  av_log(NULL, AV_LOG_DEBUG, "open ok\n");

  int count = 0;
  AVPacket pkt;
  av_init_packet(&pkt);

  while (count++ < 500) {
    ret = av_read_frame(fmt_ctx, &pkt);
    if (ret) {
      printf("pkt size: %d", pkt.size);
    }
  }

  avformat_close_input(&fmt_ctx);
  av_packet_unref(&pkt);

  av_log(NULL, AV_LOG_DEBUG, "done\n");
}
