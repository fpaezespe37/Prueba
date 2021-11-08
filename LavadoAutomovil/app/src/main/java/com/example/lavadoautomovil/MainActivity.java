package com.example.lavadoautomovil;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.example.lavadoautomovil.Registrarse;

public class MainActivity extends AppCompatActivity {
    Button ingresar;
    TextView textView;
    EditText correo;
    EditText contraseña;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        correo = (EditText)findViewById(R.id.edtCorreoIngresar);
        contraseña = (EditText)findViewById(R.id.edtContraseñaIngresar);
        textView = (TextView)findViewById(R.id.txtRegistrese);
        ingresar = (Button)findViewById(R.id.btnIngresar);
        textView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, Registrarse.class);
                startActivity(intent);
            }
        });

        ingresar.setOnClickListener(new View.OnClickListener() {
            String correoIS = correo.getText().toString();
            String contraseñaIS = contraseña.getText().toString();
            @Override
            public void onClick(View v) {
                /*if(validar()){
                    if(correoIS.equals("Admin") && contraseñaIS.equals("Admin")){
                        Toast.makeText(MainActivity.this, "Administrador",Toast.LENGTH_SHORT).show();
                    }else{

                    }
                }*/
                Intent intent = new Intent(MainActivity.this, MenuActivity.class);
                startActivity(intent);
            }
        });
    }

    public boolean validar() {
        boolean retorno = true;
        String correoS = correo.getText().toString();
        String contraseñaS = contraseña.getText().toString();

        if(correoS.isEmpty()){
            correo.setError("Campo Obligatorio");
            retorno = false;
        }
        if(contraseñaS.isEmpty()){
            contraseña.setError("Campo Obligatorio");
            retorno = false;
        }

        return retorno;
    }
}