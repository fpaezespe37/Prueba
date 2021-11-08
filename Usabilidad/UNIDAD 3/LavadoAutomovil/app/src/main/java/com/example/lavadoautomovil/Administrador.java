package com.example.lavadoautomovil;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ImageView;

public class Administrador extends AppCompatActivity {
    ImageView btnAgendar, btnConfig;
    Button btnSalir;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_administrador);
        btnAgendar = (ImageView)findViewById(R.id.imgAgendar);
        btnConfig = (ImageView)findViewById(R.id.imgConfig);
        btnSalir = (Button) findViewById(R.id.bntSalir);

        btnAgendar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(Administrador.this, AgendaAdministrador.class);
                startActivity(intent);
            }
        });
        btnConfig.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(Administrador.this,AdminConfig.class);
                startActivity(intent);
            }
        });
        btnSalir.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(Administrador.this,MainActivity.class);
                startActivity(intent);
            }
        });
    }
}