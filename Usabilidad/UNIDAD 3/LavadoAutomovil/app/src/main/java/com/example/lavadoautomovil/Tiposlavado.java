package com.example.lavadoautomovil;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.TextView;

import java.util.ArrayList;

public class Tiposlavado extends AppCompatActivity {

    private ListView lvItems;
    private Adaptador adaptador;
    private ArrayList<Entidad> arrayentidad;
    private TextView txtinput_fecha, txtinput_hora,txtinput_telefono,txtinput_ubicacion;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_tiposlavado);
        txtinput_fecha = findViewById(R.id.txt_fecha);
        txtinput_hora = findViewById(R.id.txt_hora);
        txtinput_telefono = findViewById(R.id.txt_telefono);
        txtinput_ubicacion = findViewById(R.id.txt_ubicacion);

        String fech, hor, telef, ubic;
        Intent intent = getIntent();
        Bundle extras = intent.getExtras();
        fech = extras.getString("Fecha");
        hor = extras.getString("Hora");
        telef = extras.getString("Telefono");
        ubic = extras.getString("Direccion");

        txtinput_fecha.setText(fech);
        txtinput_hora.setText( hor);
        txtinput_telefono.setText(telef);
        txtinput_ubicacion.setText(ubic);


        lvItems = findViewById(R.id.lvItems);
        arrayentidad = GetArrayItems();
        adaptador = new Adaptador(this, arrayentidad);
        lvItems.setAdapter(adaptador);
        lvItems.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                //Intent intent = new Intent(Tiposlavado.this, Confirmacion.class);

                String spin,spin1,spin2,spin3,spin4;
                spin = txtinput_fecha.getText().toString().trim();
                spin1 = txtinput_hora.getText().toString().trim();
                spin2 = txtinput_telefono.getText().toString().trim();
                spin3 = txtinput_ubicacion.getText().toString().trim();
                //spin2 = edtfecha.getText().toString().trim();
                //tipos = spinnerCountries.getSelectedItem().toString().trim();
                Bundle extras = new Bundle();
                extras.putString("Fecha", spin);
                extras.putString("Hora", spin1);
                extras.putString("Telefono", spin2);
                extras.putString("Direccion", spin3);

                //extras.putString("Tipo Lavado", tipos);
                //extras
                Intent intent = new Intent(Tiposlavado.this, Confirmacion.class);
                intent.putExtra("ObjetoData", arrayentidad.get(position));

                intent.putExtras(extras);
                startActivity(intent);




            }
        });

    }
    private ArrayList<Entidad> GetArrayItems(){
        ArrayList<Entidad> listItems = new ArrayList<>();
        listItems.add(new Entidad(1,R.drawable.img_camioneta, "AUTOMOVIL + EXPRESS", "$5"));
        listItems.add(new Entidad(2,R.drawable.img_camioneta, "AUTOMOVIL + COMPLETO", "$8"));
        listItems.add(new Entidad(3,R.drawable.img_car, "CAMIONETA + EXPRESS", "$8"));
        listItems.add(new Entidad(4,R.drawable.img_car, "CAMIONETA + COMPLETO", "$12"));

        return listItems;
    }

}