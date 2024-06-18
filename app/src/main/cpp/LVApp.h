#ifndef LVGLPORTANDROID_LVAPP_H
#define LVGLPORTANDROID_LVAPP_H

#include <jni.h>
#include <thread>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <lvgl.h>
#include "AppList.h"

class LVApp {
private:
    ANativeWindow *window = nullptr;
    ANativeWindow_Buffer windowBuffer;
    int app_width = 240, app_height = 240;
    int screen_width = 0, screen_height = 0;
    lv_disp_draw_buf_t draw_buf;
    lv_disp_drv_t disp_drv;
    lv_indev_drv_t indev_drv;
    uint16_t *surface_buf = nullptr;
    size_t surface_size = 0;
    string app_name;
    atomic<int> isTouch, touchX, touchY;
    atomic<bool> is_running = false;

    void lv_flush_callback(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);

    void lv_touch_callback(lv_indev_drv_t *indev_driver, lv_indev_data_t *data);

    void lv_loop_task();

    static void lv_log_print(const char *txt);

    static void lv_flush_cb_static(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);

    static void lv_touch_cb_static(lv_indev_drv_t *indev_driver, lv_indev_data_t *data);

public:
    void start(ANativeWindow *window);

    void setApp(const char *name);

    void onTouch(int touch, int x, int y);

    void stop();
};


#endif //LVGLPORTANDROID_LVAPP_H
