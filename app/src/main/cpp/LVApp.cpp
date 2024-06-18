#include <thread>
#include <mutex>
#include "LVApp.h"
#include "LVHelper.h"
#include <lv_demos.h>
#include <unistd.h>

using namespace std;

void LVApp::lv_flush_callback(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
    if (is_running) {
        if (surface_buf == nullptr) {
            surface_size = sizeof(uint16_t) * windowBuffer.stride * windowBuffer.height;
            surface_buf = (uint16_t *) malloc(surface_size);
        }
        int w = area->x2 - area->x1 + 1;
        int h = area->y2 - area->y1 + 1;
        auto *src = &(color_p->full);
        auto stride = windowBuffer.stride;
        for (int i = 0; i < h; i++) {
            auto *dst = &surface_buf[(area->y1 + i) * stride + area->x1];
            memcpy(dst, &src[i * w], sizeof(uint16_t) * w);
            for (int j = 0; j < w; j++) {
                dst[j] = ((dst[j] & 0xFF00) >> 8) | ((dst[j] & 0x00FF) << 8);
            }
        }
        if (ANativeWindow_lock(window, &windowBuffer, nullptr) == 0) {
            auto *dst = (uint32_t *) windowBuffer.bits;
            memcpy(dst, surface_buf, surface_size);
            ANativeWindow_unlockAndPost(window);
        }
    }
    lv_disp_flush_ready(disp);
}

void LVApp::lv_touch_callback(lv_indev_drv_t *indev_driver, lv_indev_data_t *data) {
    if (isTouch) {
        data->point.x = (short) touchX;
        data->point.y = (short) touchY;
        data->state = LV_INDEV_STATE_PR;
    } else {
        data->state = LV_INDEV_STATE_REL;
    }
}

void LVApp::lv_log_print(const char *txt) {
    LOGD("%s", txt);
}

void LVApp::start(ANativeWindow *win) {
    this->window = win;
    screen_width = ANativeWindow_getWidth(window);
    screen_height = ANativeWindow_getHeight(window);
    ANativeWindow_setBuffersGeometry(window, app_width, app_height, WINDOW_FORMAT_RGB_565);
    LOGD("LV Screen [%d x %d]", app_width, app_height);
    is_running = true;
    thread lv_thread(&LVApp::lv_loop_task, this);
    lv_thread.detach();
}

void LVApp::lv_loop_task() {
    LOGD("LV Task Start!!");
    lv_init();
    size_t buf_size = sizeof(lv_color_t) * app_width * app_height;
    auto *buf = malloc(buf_size);
    lv_disp_draw_buf_init(&draw_buf, buf, nullptr, app_width * app_height);
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf = &draw_buf;
    disp_drv.hor_res = (short) app_width;
    disp_drv.ver_res = (short) app_height;
    disp_drv.user_data = this;
    disp_drv.flush_cb = &lv_flush_cb_static;
    lv_disp_drv_register(&disp_drv);
    lv_indev_drv_init(&indev_drv);

    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.user_data = this;
    indev_drv.read_cb = &lv_touch_cb_static;
    lv_indev_drv_register(&indev_drv);
    lv_log_register_print_cb(&lv_log_print);

    auto *lv_app_func = lv_ci_example_list.at("default");
    auto search = lv_ci_example_list.find(app_name);
    if (search != lv_ci_example_list.end()) {
        lv_app_func = search->second;
    }
    lv_app_func();
    ANativeWindow_acquire(window);
    if (ANativeWindow_lock(window, &windowBuffer, nullptr) == 0) {
        ANativeWindow_unlockAndPost(window);
    }
    while (is_running) {
        lv_timer_handler();
        usleep(1000);
    }
    ANativeWindow_release(window);
    //lv_deinit();
    free(buf);
    if (surface_buf != nullptr) {
        free(surface_buf);
        surface_buf = nullptr;
    }
    window = nullptr;
    LOGD("LV App Stopped!!");
}

void LVApp::stop() {
    is_running = false;
}

void LVApp::onTouch(int touch, int x, int y) {
    isTouch = touch;
    touchX = x * app_width / screen_width;
    touchY = y * app_height / screen_height;
}

void LVApp::lv_flush_cb_static(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
    auto *app = (LVApp *) disp->user_data;
    app->lv_flush_callback(disp, area, color_p);
}

void LVApp::lv_touch_cb_static(lv_indev_drv_t *indev_driver, lv_indev_data_t *data) {
    auto *app = (LVApp *) indev_driver->user_data;
    app->lv_touch_callback(indev_driver, data);
}

void LVApp::setApp(const char *name) {
    this->app_name = name;
}
