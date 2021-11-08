package com.example.lavadoautomovil;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

import java.util.ArrayList;

public class Confirmacion extends AppCompatActivity {

    TextView txt_hora,txt_tipos;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_confirmacion);
        txt_tipos = findViewById(R.id.txt_tipos);
        txt_hora = findViewById(R.id.txt_hora);

        String hora, carros;
        Intent intent = getIntent();


        Bundle extras = intent.getExtras();
        hora = extras.getString("Hora");
        carros = extras.getString("Tipo Lavado");


        txt_hora.setText( hora);
        txt_tipos.setText(carros);
        //String hora;
        //hora = intent.getDataString();

        //txt_hora.setText(hora);



    }
}