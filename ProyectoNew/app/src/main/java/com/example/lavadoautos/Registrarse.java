package com.example.lavadoautos;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;

public class Registrarse extends AppCompatActivity {
    TextView ingresar;
    ImageView facebook, google;
    Button registrarse;
    EditText nombre,correo, contraseña;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_registrarse);
        facebook = (ImageView)findViewById(R.id.imgFb);
        google = (ImageView)findViewById(R.id.imgGoogle);
        ingresar = (TextView)findViewById(R.id.txtRegistrese);
        registrarse = (Button)findViewById(R.id.btnIngresar);

        facebook.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                gotoUrl("https://www.facebook.com/");
            }
        });

        google.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                gotoUrl("https://accounts.google.com/");
            }
        });

        ingresar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(Registrarse.this, MainActivity.class);
                startActivity(intent);
            }
        });

        registrarse.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intentB = new Intent(Registrarse.this, MainActivity.class);
                startActivity(intentB);
            }
        });
    }

    private void gotoUrl(String s) {
        Uri uri = Uri.parse(s);
        startActivity(new Intent(Intent.ACTION_VIEW,uri));
    }

    public boolean validar() {
        boolean retorno = true;
        String correoS = correo.getText().toString();
        String contraseñaS = contraseña.getText().toString();
        String nombreS = nombre.getText().toString();

        if(correoS.isEmpty()){
            correo.setError("Campo Obligatorio");
            retorno = false;
        }
        if(contraseñaS.isEmpty()){
            contraseña.setError("Campo Obligatorio");
            retorno = false;
        }
        if(nombreS.isEmpty()){
            nombre.setError("Campo Obligatorio");
            retorno = false;
        }

        return retorno;
    }
}