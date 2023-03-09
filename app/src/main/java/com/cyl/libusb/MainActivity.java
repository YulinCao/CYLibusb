package com.cyl.libusb;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

import com.cyl.libusb.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'libusb' library on application startup.
    static {
        System.loadLibrary("UsbUtils");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        LibusbUtils.initUsb();
    }

}