package com.example.lavadoautomovil;

import androidx.appcompat.app.AppCompatActivity;

import android.app.AlertDialog;
import android.app.ProgressDialog;
import android.content.Intent;
import android.net.Uri;
import android.os.AsyncTask;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.freddypaez.carwashdll.wsServicios;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

import Clases.EPersona;
import Clases.EReservas;

public class Registrarse extends AppCompatActivity {

    String namespace;
    String url;
    String methodName;

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
                Intent intent = new Intent(Registrarse.this, MainActivity.class);
                startActivity(intent);
            }
        });

        registrarse.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!emptyValidation()) {

                    //consultawsValidacionEqDesdeFuncion("consultarPersona");
                    consultawsValidacionEqDesdeFuncion("");
                    dbHelper.addUser(new User(correo.getText().toString(), contraseña.getText().toString()));
                    Toast.makeText(Registrarse.this, "Usuario Agregado", Toast.LENGTH_SHORT).show();
                    correo.setText("");
                    contraseña.setText("");
                    Intent inte = new Intent(Registrarse.this,MainActivity.class);
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


    private void consultawsValidacionEqDesdeFuncion(String MetodoEjecutar )
    {
        //EjecutaBarraProgreso();
        AsyncCallWSDispositivos task = new AsyncCallWSDispositivos();
        //task.execute("BuscarServicios");
        task.execute("InsertarPersona");
        //task.execute("InsertaReserva");
        //task.execute("BuscarReserva");
    }

    //LLAMDAS AL WS SERBVICE

    private class AsyncCallWSDispositivos extends AsyncTask<String, Void, ArrayList<EReservas>> {

        ProgressDialog pDialog;

        @Override
        protected void onPreExecute() {


            pDialog = new ProgressDialog(Registrarse.this);
            pDialog.setMessage("Procesando....");
            pDialog.setIndeterminate(true);
            pDialog.setCancelable(false);
            pDialog.show();

        }

        @Override
        protected ArrayList<EReservas> doInBackground(String... params) {
            String respuesta="";
            namespace = "http://tempuri.org/";
            url ="http://www.carwash.somee.com/wsCarWash.asmx";
            methodName = params[0];

            ArrayList<EPersona> respuestaWS = new ArrayList<EPersona>();
            ArrayList<EReservas> respuestaReservasWS = new ArrayList<EReservas>();
            Map<String, String> listParams = new HashMap<String, String>();



            listParams.put("cedula", correo.getText().toString());
            listParams.put("correo", correo.getText().toString());
            listParams.put("password",contraseña.getText().toString());
            listParams.put("nombrePersona",correo.getText().toString());
            listParams.put("tipoUsuario","2"); //2 cliente, //1 admin
            listParams.put("celular",correo.getText().toString()); //2 cliente, //1 admin
            listParams.put("tipobusqueda","0");

            /*
            // INSERTA RESERVAS
            listParams.put("IdReserva", "0");
            listParams.put("IdServicio", "1");
            listParams.put("CedulaPersona", "1713");
            listParams.put("TipoBusqueda","0");
            listParams.put("Observacion","0");
            listParams.put("Cancelado","false");
            listParams.put("RegistroNuevo","true");
            listParams.put("Fecha","2021/03/24");
            listParams.put("Hora","10:30");

*/



            //listParams.put("FechaReservacionServicio", (new SimpleDateFormat("dd/MM/yyyy").parse(fechaNacimiento.getText().toString())););



            wsServicios wsServicios = new wsServicios(namespace,url,methodName,listParams);
            try {
                switch (params[0]) {
                    case "BuscarServicios":
                        //respuestaWS = new wsServicios(namespace,url,methodName,listParams).consultarServiciosActivos();
                        break;
                    case "BuscarPersona":
                        respuestaWS = new wsServicios(namespace,url,methodName,listParams).consultarPersona();
                        //resultado = "";
                        break;
                    case "InsertarPersona":
                        //insertarPersona(listParams);
                        respuestaWS = new wsServicios(namespace,url,methodName,listParams).insertarPersona();
                        break;
                    case  "InsertaReserva":
                        //insertarReservas(listParams);
                        respuestaReservasWS = new wsServicios(namespace,url,methodName,listParams).insertarReservas();
                        break;
                    case  "BuscarReserva":
                        //consultarReserva(listParams);
                        respuestaReservasWS = new wsServicios(namespace,url,methodName,listParams).consultarReserva();
                        break;
                }
            } catch (Exception e1) {
                String resultado = e1.toString();
            }

            return  respuestaReservasWS;
        }

        @Override
        protected void onPostExecute(ArrayList<EReservas> respuestaWSVerificaImei) {
            AlertDialog.Builder dialogo = new AlertDialog.Builder(Registrarse.this);


            //CargarActivityEvaluaDispositivo();
            // progressBar.setVisibility(View.GONE);
            //txtProgress.setText("");
            pDialog.dismiss();
        }

    }

}