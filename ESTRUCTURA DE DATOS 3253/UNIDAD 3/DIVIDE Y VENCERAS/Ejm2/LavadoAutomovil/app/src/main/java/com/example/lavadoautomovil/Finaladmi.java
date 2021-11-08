package com.example.lavadoautomovil;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class Finaladmi extends AppCompatActivity {

    private Button btn_admisalir;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_finaladmi);
        btn_admisalir = findViewById(R.id.btn_admisalir);


        btn_admisalir.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(Finaladmi.this, Administrador.class);
                startActivity(intent);;
            }
        });
    }
}