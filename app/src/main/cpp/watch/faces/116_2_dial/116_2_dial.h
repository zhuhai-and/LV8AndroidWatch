
// File generated by bin2lvgl
// developed by fbiego. 
// https://github.com/fbiego
// Watchface: 116_2_DIAL

#ifndef _FACE_116_2_DIAL_H
#define _FACE_116_2_DIAL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"
#include "app_hal.h"

#define ENABLE_FACE_116_2_DIAL // (Outline) uncomment to enable or define it elsewhere

#ifdef ENABLE_FACE_116_2_DIAL
    extern lv_obj_t *face_116_2_dial;
	extern lv_obj_t *face_116_2_dial_0_384;
	extern lv_obj_t *face_116_2_dial_1_59716;
	extern lv_obj_t *face_116_2_dial_2_59716;
	extern lv_obj_t *face_116_2_dial_3_62316;
	extern lv_obj_t *face_116_2_dial_4_62316;
	extern lv_obj_t *face_116_2_dial_5_114030;
	extern lv_obj_t *face_116_2_dial_6_114030;
	extern lv_obj_t *face_116_2_dial_8_58492;
	extern lv_obj_t *face_116_2_dial_18_162424;


	LV_IMG_DECLARE(face_116_2_dial_dial_img_0_384_0);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_1_59716_0);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_1_59716_1);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_1_59716_2);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_1_59716_3);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_1_59716_4);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_1_59716_5);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_1_59716_6);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_1_59716_7);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_1_59716_8);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_1_59716_9);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_3_62316_0);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_3_62316_1);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_3_62316_2);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_3_62316_3);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_3_62316_4);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_3_62316_5);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_3_62316_6);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_3_62316_7);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_3_62316_8);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_3_62316_9);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_5_114030_0);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_5_114030_1);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_5_114030_2);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_5_114030_3);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_5_114030_4);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_5_114030_5);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_5_114030_6);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_5_114030_7);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_5_114030_8);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_5_114030_9);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_8_58492_0);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_9_157828_0);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_10_156106_0);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_11_153152_0);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_12_151838_0);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_13_154678_0);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_14_165314_0);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_15_60830_0);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_16_150496_0);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_17_159548_0);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_17_159548_1);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_17_159548_2);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_17_159548_3);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_17_159548_4);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_17_159548_5);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_17_159548_6);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_18_162424_0);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_18_162424_1);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_18_162424_2);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_18_162424_3);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_18_162424_4);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_18_162424_5);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_18_162424_6);
	LV_IMG_DECLARE(face_116_2_dial_dial_img_preview_0);


#endif
    void onFaceEvent(lv_event_t * e);

    void init_face_116_2_dial(void (*callback)(const char*, const lv_img_dsc_t *, lv_obj_t **));
    void update_time_116_2_dial(int second, int minute, int hour, bool mode, bool am, int day, int month, int year, int weekday);
    void update_weather_116_2_dial(int temp, int icon);
    void update_status_116_2_dial(int battery, bool connection);
    void update_activity_116_2_dial(int steps, int distance, int kcal);
    void update_health_116_2_dial(int bpm, int oxygen);
    void update_all_116_2_dial(int second, int minute, int hour, bool mode, bool am, int day, int month, int year, int weekday, 
                int temp, int icon, int battery, bool connection, int steps, int distance, int kcal, int bpm, int oxygen);
    void update_check_116_2_dial(lv_obj_t *root, int second, int minute, int hour, bool mode, bool am, int day, int month, int year, int weekday, 
                int temp, int icon, int battery, bool connection, int steps, int distance, int kcal, int bpm, int oxygen);


#ifdef __cplusplus
}
#endif

#endif
