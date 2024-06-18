package com.lvgl.watch.demo.ui;

import android.os.Bundle;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.lvgl.watch.demo.databinding.ActivityFullScreenBinding;


public class FullScreenActivity extends AppCompatActivity {
    private ActivityFullScreenBinding mB;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mB = ActivityFullScreenBinding.inflate(getLayoutInflater());
        setContentView(mB.getRoot());
        mB.lvView.setApp("watch");
    }
}
