package com.example.lavadoautomovil;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class Admcitas extends AppCompatActivity {

    private Button btn_confirmar;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_admcitas);
        btn_confirmar = findViewById(R.id.btn_confirmar);

        btn_confirmar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(Admcitas.this, Admin.class);
                startActivity(intent);
            }
        });


    }
}