package com.example.lavadoautomovil;

import androidx.appcompat.app.AppCompatActivity;

import android.app.admin.DeviceAdminService;
import android.content.Intent;
import android.os.Bundle;
import android.text.Editable;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;


import java.util.ArrayList;

public class Admlogin extends AppCompatActivity  {




    private Button btnadmin;
    private EditText correo;
    private EditText password;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_admlogin);
        btnadmin = findViewById(R.id.btningresar);
        correo = findViewById(R.id.correoinput);
        password = findViewById(R.id.passwinput);
        btnadmin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(validar()){

                }
                if(correo.getText().toString().equals("freddyjair37@gmail.com") && password.getText().toString().equals("1234"))
                {

                    Intent intent = new Intent(Admlogin.this, Admin.class);
                    startActivity(intent);
                    Toast.makeText(Admlogin.this, "Bienvenido al sistema de administrador", Toast.LENGTH_SHORT).show();


                }else{
                    Toast.makeText(Admlogin.this, "Correo o clave incorrectos, intente nuevamente",Toast.LENGTH_SHORT).show();
                }

            }
        });


    }
    public boolean validar(){
        boolean retorno=true;

        String c1 = correo.getText().toString();
        String c2 = password.getText().toString();
        if(c1.isEmpty())
        {
            correo.setError("Este campo no puede quedar vacio");
            retorno = false;
        }
        if(c2.isEmpty())
        {
            password.setError("Este campo no puede quedar vacio");
            retorno = false;
        }

        return retorno;
    }
}