package com.lvgl.watch.demo.ui;

import android.content.Intent;
import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;

import com.blankj.utilcode.util.ActivityUtils;
import com.lvgl.watch.demo.databinding.ActivityMainBinding;


public class MainActivity extends AppCompatActivity {

    private ActivityMainBinding mB;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mB = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(mB.getRoot());
        mB.btnWidgets.setOnClickListener(v -> openPartPage("widgets"));
        mB.btnMusic.setOnClickListener(v -> openPartPage("music"));
        mB.btnBenchmark.setOnClickListener(v -> openPartPage("benchmark"));
        mB.btnPvz.setOnClickListener(v -> openPartPage("pvz"));
        mB.btnTetris.setOnClickListener(v -> openPartPage("tetris"));
        mB.btnLarge.setOnClickListener(v -> ActivityUtils.startActivity(FullScreenActivity.class));
    }

    private void openPartPage(String name) {
        Intent intent = new Intent(this, PartScreenActivity.class);
        intent.putExtra("app", name);
        startActivity(intent);
    }
}
