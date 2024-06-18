#ifndef LVGL_ANDROID_SIMPLE_LVTICKER_H
#define LVGL_ANDROID_SIMPLE_LVTICKER_H

#include <stdio.h>
#include <time.h>

unsigned long lv_millis() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

#endif
