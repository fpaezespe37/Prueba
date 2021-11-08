package com.example.lavadoautomovil;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.TextView;

public class Prueba extends AppCompatActivity {

    private TextView txt_prueba;
    private Entidad Item;
    private TextView titulo, descripcion;
    private ImageView imgFoto;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_prueba);

        Item = (Entidad) getIntent().getSerializableExtra("ObjetoData");

        titulo = findViewById(R.id.txt_prueba);
        descripcion = findViewById(R.id.Descrp);
        imgFoto = findViewById(R.id.ImgFoto);

        titulo.setText(Item.getTitulo());
        imgFoto.setImageResource(Item.getImgFoto());
        descripcion.setText(Item.getContenido())    ;

    }
}