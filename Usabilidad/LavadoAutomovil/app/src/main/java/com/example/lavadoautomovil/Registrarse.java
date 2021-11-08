package com.example.lavadoautomovil;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

public class Registrarse extends AppCompatActivity {
    TextView ingresar;
    ImageView facebook, google;
    Button registrarse;
    EditText correo, contraseña;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_registrarse);
        facebook = (ImageView) findViewById(R.id.imgFb);
        google = (ImageView) findViewById(R.id.imgGoogle);
        ingresar = (TextView) findViewById(R.id.txtRegistrese);
        registrarse = (Button) findViewById(R.id.btSignIn);
        correo = (EditText) findViewById(R.id.emailinput);
        contraseña = (EditText) findViewById(R.id.passwordinput);
        final DatabaseHelper dbHelper = new DatabaseHelper(this);

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
                Intent intent = new Intent(Registrarse.this, Userlogin.class);
                startActivity(intent);
            }
        });

        registrarse.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!emptyValidation()) {
                    dbHelper.addUser(new User(correo.getText().toString(), contraseña.getText().toString()));
                    Toast.makeText(Registrarse.this, "Usuario Agregado", Toast.LENGTH_SHORT).show();
                    correo.setText("");
                    contraseña.setText("");
                    Intent inte = new Intent(Registrarse.this, Userlogin.class);
                    startActivity(inte);
                } else {
                    Toast.makeText(Registrarse.this, "Campos Vacios", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    private void gotoUrl(String s) {
        Uri uri = Uri.parse(s);
        startActivity(new Intent(Intent.ACTION_VIEW, uri));
    }

    private boolean emptyValidation() {
        if (TextUtils.isEmpty(correo.getText().toString()) || TextUtils.isEmpty(contraseña.getText().toString())) {
            return true;
        } else {
            return false;
        }
    }
}