package com.lvgl.watch.demo;

import android.app.Application;

import com.blankj.utilcode.util.Utils;

public class MainApp extends Application {

    @Override
    public void onCreate() {
        super.onCreate();
        Utils.init(this);
    }
}
