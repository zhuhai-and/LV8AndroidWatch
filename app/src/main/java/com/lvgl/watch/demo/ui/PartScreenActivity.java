package com.lvgl.watch.demo.ui;

import android.os.Bundle;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.lvgl.watch.demo.databinding.ActivityPartScreenBinding;


public class PartScreenActivity extends AppCompatActivity {
    private ActivityPartScreenBinding mB;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mB = ActivityPartScreenBinding.inflate(getLayoutInflater());
        setContentView(mB.getRoot());
        String name = getIntent().getStringExtra("app");
        if (name != null) {
            mB.lvView.setApp(name);
        }
    }
}
