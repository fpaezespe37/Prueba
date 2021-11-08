package com.example.lavadoautomovil;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.VerifiedInputEvent;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.ListView;

import java.util.ArrayList;

public class Tiposlav extends AppCompatActivity {

    private ListView lvItems;
    private Adaptador adaptador;
    private ArrayList<Entidad> arrayentidad;
    Button btn_enviar;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_tiposlav);
        btn_enviar = findViewById(R.id.btn_enviar);
        lvItems = findViewById(R.id.lvItems);
        arrayentidad = GetArrayItems();
        adaptador = new Adaptador(this, arrayentidad);
        lvItems.setAdapter(adaptador);


        lvItems.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Intent intent = new Intent(Tiposlav.this, Prueba.class);
                intent.putExtra("ObjetoData", arrayentidad.get(position));


                startActivity(intent);
            }
        });

        btn_enviar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                Intent intent = new Intent(Tiposlav.this, Prueba.class);

                startActivity(intent);


            }
        });
    }


    private ArrayList<Entidad> GetArrayItems(){
        ArrayList<Entidad> listItems = new ArrayList<>();
        listItems.add(new Entidad(R.drawable.img_camioneta, "AUTOMOVIL + EXPRESS", "$5"));
        listItems.add(new Entidad(R.drawable.img_camioneta, "AUTOMOVIL + COMPLETO", "$8"));
        listItems.add(new Entidad(R.drawable.img_car, "CAMIONETA + EXPRESS", "$8"));
        listItems.add(new Entidad(R.drawable.img_car, "CAMIONETA + EXPRESS", "$12"));

        return listItems;
    }

}