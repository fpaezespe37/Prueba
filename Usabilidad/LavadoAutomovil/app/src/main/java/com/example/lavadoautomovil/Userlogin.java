package com.example.lavadoautomovil;

import android.content.Intent;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class Userlogin extends AppCompatActivity {

    private Button btSignIn;
    private EditText edtEmail;
    private EditText edtPassword;
    private TextView registrese;
    private TextView loginadmin;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.userlogin);


        btSignIn = findViewById(R.id.btSignIn);
        edtEmail = findViewById(R.id.emailinput);
        edtPassword = findViewById(R.id.passwordinput);
        registrese = findViewById(R.id.txtRegistrese);
        loginadmin = findViewById(R.id.txtadmin);
        final DatabaseHelper dbHelper = new DatabaseHelper(this);

        btSignIn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(validar())
                {

                }
                if (!emptyValidation()) {
                    User user = dbHelper.queryUser(edtEmail.getText().toString(), edtPassword.getText().toString());
                    if (user != null) {
                        Bundle mBundle = new Bundle();
                        mBundle.putString("user", user.getEmail());
                        Intent intent = new Intent(Userlogin.this, MenuActivity.class);
                        intent.putExtras(mBundle);
                        startActivity(intent);
                        Toast.makeText(Userlogin.this, "Bienvenido " + user.getEmail(), Toast.LENGTH_SHORT).show();
                    } else {
                        Toast.makeText(Userlogin.this, "Usuario No Encontrado", Toast.LENGTH_SHORT).show();
                        edtPassword.setText("");
                    }
                }else{
                    Toast.makeText(Userlogin.this, "Campos Vacios", Toast.LENGTH_SHORT).show();
                }
            }
        });

        registrese.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(Userlogin.this, Registrarse.class);
                startActivity(intent);;
            }
        });

        loginadmin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(Userlogin.this, Admlogin.class);
                startActivity(intent);
            }
        });
    }

    public boolean validar(){
        boolean retorno=true;

        String c1 = edtEmail.getText().toString();
        String c2 = edtPassword.getText().toString();
        if(c1.isEmpty())
        {
            edtEmail.setError("Este campo no puede quedar vacio");
            retorno = false;
        }
        if(c2.isEmpty())
        {
            edtPassword.setError("Este campo no puede quedar vacio");
            retorno = false;
        }

        return retorno;
    }


    private boolean emptyValidation() {
        if (TextUtils.isEmpty(edtEmail.getText().toString()) || TextUtils.isEmpty(edtPassword.getText().toString())) {
            return true;
        }else {
            return false;
        }
    }
}
