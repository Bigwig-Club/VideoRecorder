//
//  media.h
//  VideoRecorder
//
//  Created by 马良 on 2020/10/9.
//

#ifndef media_h
#define media_h

#include <stdio.h>
#include "libavutil/avutil.h"
#include "libavdevice/avdevice.h"
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"

void open_media(void);

#endif /* media_h */
