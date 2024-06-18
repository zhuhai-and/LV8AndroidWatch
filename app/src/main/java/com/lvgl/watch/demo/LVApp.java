package com.lvgl.watch.demo;

import android.view.Surface;

public class LVApp {

    private long mInstanceId;

    /**
     * Only One instance in a running time due to LVGL limit
     */
    public LVApp() {
        mInstanceId = nCreate();
    }

    public long start(Surface surface) {
        return nStart(mInstanceId, surface);
    }

    public long setApp(String name) {
        return nSetApp(mInstanceId, name);
    }

    public long onTouch(int touch, int x, int y) {
        return nOnTouch(mInstanceId, touch, x, y);
    }

    public long stop() {
        return nStop(mInstanceId);
    }

    public void destroy() {
        nDestroy(mInstanceId);
        mInstanceId = 0;
    }

    private static native long nCreate();

    private static native long nSetApp(long id, String name);

    private static native long nStart(long id, Surface surface);

    private static native long nOnTouch(long id, int touch, int x, int y);

    private static native long nStop(long id);

    private static native long nDestroy(long id);

    static {
        System.loadLibrary("lvApp");
    }
}
