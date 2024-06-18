#ifndef LVGLPORTANDROID_APPLIST_H
#define LVGLPORTANDROID_APPLIST_H

#include <iostream>
#include <map>
#include <lv_demos.h>
#include "app_hal.h"

using namespace std;

const map<string, void (*)(void)> lv_ci_example_list{
        {"default", lv_demo_widgets},
        {"widgets", lv_demo_widgets},
        {"watch",   hal_setup},
};

#endif //LVGLPORTANDROID_APPLIST_H
