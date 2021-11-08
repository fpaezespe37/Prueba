package com.example.lavadoautomovil;

import android.app.AlertDialog;
import android.app.ProgressDialog;
import android.content.Intent;
import androidx.appcompat.app.AppCompatActivity;

import android.os.AsyncTask;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.freddypaez.carwashdll.wsServicios;

import org.ksoap2.SoapEnvelope;
import org.ksoap2.serialization.PropertyInfo;
import org.ksoap2.serialization.SoapObject;
import org.ksoap2.serialization.SoapSerializationEnvelope;
import org.ksoap2.transport.HttpTransportSE;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import Clases.Deserealiza;
import Clases.EPersona;
import Clases.EReservas;

public class MainActivity extends AppCompatActivity {

    String namespace;
    String url;
    String methodName;

    private Button btSignIn;
    private EditText edtEmail;
    private EditText edtPassword;
    private TextView registrese;
    private Button btnTemp;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        btSignIn = findViewById(R.id.btSignIn);
        edtEmail = findViewById(R.id.emailinput);
        edtPassword = findViewById(R.id.passwordinput);
        registrese = findViewById(R.id.txtRegistrese);




        final DatabaseHelper dbHelper = new DatabaseHelper(this);

        btSignIn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {


                if (!emptyValidation()) {

                    consultawsBuscaPersona("consultarPersona");

                    String emailAdmin, passAdmin;
                    User user = dbHelper.queryUser(edtEmail.getText().toString(), edtPassword.getText().toString());
                    if (user != null) {
                    emailAdmin = user.getEmail();
                    passAdmin = user.getPassword();
                    int validacion = validarAdmin(emailAdmin,passAdmin);

                    ///////


                    /*
                    switch(validacion){
                        case 1:
                            Intent intentAdmin = new Intent(MainActivity.this, Administrador.class);
                            startActivity(intentAdmin);
                            Toast.makeText(MainActivity.this, "Bienvenido Administrador", Toast.LENGTH_SHORT).show();
                            break;
                        case 0:
                            Bundle mBundle = new Bundle();
                            mBundle.putString("user", user.getEmail());
                            Intent intent = new Intent(MainActivity.this, MenuActivity.class);
                            intent.putExtras(mBundle);
                            startActivity(intent);
                            Toast.makeText(MainActivity.this, "Bienvenido " + user.getEmail(), Toast.LENGTH_SHORT).show();
                            break;
                    }*/
                    }else {
                        //Toast.makeText(MainActivity.this, "Usuario No Encontrado", Toast.LENGTH_SHORT).show();
                        edtPassword.setText("");
                    }
                }else{
                    Toast.makeText(MainActivity.this, "Campos Vacios", Toast.LENGTH_SHORT).show();
                }
            }
        });

        registrese.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, Registrarse.class);
                startActivity(intent);
            }
        });
    }



    public int validarAdmin(String email, String pass){
        if(email.equals("admin21@gmail.com") && pass.equals("Admin2021")){
            return 1;
        }else{
            return 0;
        }
    }

    private boolean emptyValidation() {
        if (TextUtils.isEmpty(edtEmail.getText().toString()) || TextUtils.isEmpty(edtPassword.getText().toString())) {
            return true;
        }else {
            return false;
        }
    }



    private void consultawsBuscaPersona(String MetodoEjecutar )
    {
        //EjecutaBarraProgreso();
        AsyncCallWSBuscaPersona task1 = new AsyncCallWSBuscaPersona();
        task1.execute("BuscarPersona");
        //task.execute("InsertaReserva");
        //task.execute("BuscarReserva");
    }

    //LLAMDAS AL WS SERBVICE

    private class AsyncCallWSBuscaPersona  extends AsyncTask<String, Void, ArrayList<EPersona>> {

        ProgressDialog pDialog;

        @Override
        protected void onPreExecute() {

            pDialog = new ProgressDialog(MainActivity.this);
            pDialog.setMessage("Procesando....");
            pDialog.setIndeterminate(true);
            pDialog.setCancelable(false);
            pDialog.show();

        }

        @Override
        protected ArrayList<EPersona> doInBackground(String... params) {
            String respuesta="";
            namespace = "http://tempuri.org/";
            url ="http://www.carwash.somee.com/wsCarWash.asmx";
            methodName = params[0];

            ArrayList<EPersona> respuestaWS = new ArrayList<EPersona>();
            ArrayList<EPersona> respuestaReservasWS = new ArrayList<EPersona>();
            Map<String, String> listParams = new HashMap<String, String>();



            listParams.put("cedula", "");
            listParams.put("correo", edtEmail.getText().toString());
            listParams.put("password", edtPassword.getText().toString());
            listParams.put("nombrePersona","frevin@gmail.com");
            listParams.put("tipoUsuario","2"); //2 cliente, //1 admin
            listParams.put("celular","frevin@gmail.com"); //2 cliente, //1 admin
            listParams.put("tipobusqueda","3");


            wsServicios wsServicios = new wsServicios(namespace,url,methodName,listParams);
            try {
                switch (params[0]) {
                    case "BuscarServicios":
                        //respuestaWS = new wsServicios(namespace,url,methodName,listParams).consultarServiciosActivos();
                        break;
                    case "BuscarPersona":
                        //consultarPersona(listParams);
                        respuestaWS = new wsServicios(namespace,url,methodName,listParams).consultarPersona();
                        //resultado = "";
                        break;
                    case "InsertarPersona":
                        //insertarPersona(listParams);
                        respuestaWS = new wsServicios(namespace,url,methodName,listParams).insertarPersona();
                        break;
                    /*case  "InsertaReserva":
                        //insertarReservas(listParams);
                        respuestaReservasWS = new wsServicios(namespace,url,methodName,listParams).insertarReservas();
                        break;
                    case  "BuscarReserva":
                        //consultarReserva(listParams);
                        respuestaReservasWS = new wsServicios(namespace,url,methodName,listParams).consultarReserva();
                        break;*/
                }
            } catch (Exception e1) {
                String resultado = e1.toString();
            }

            return  respuestaWS;
        }

        @Override
        protected void onPostExecute(ArrayList<EPersona> respuestaWSVerificaImei) {
            AlertDialog.Builder dialogo = new AlertDialog.Builder(MainActivity.this);
            pDialog.dismiss();
            List<EPersona> lstPersonas = new ArrayList<EPersona>();
            for (EPersona persona : respuestaWSVerificaImei) {
                //clave = categoria.getNombreCategoria();
                if (persona.getMail() != null ) {
                    //lstCategorias.add(new EPersona(categoria.getIdServicio(), categoria.getNombreServicio(),categoria.getPrecioServicio()));
                    //lstPersonas.add(new EPersona(persona.getNombrePersona(), persona.getCedulaPersona(),persona.getMail()));
                    lstPersonas.add(new EPersona(persona.getIdTipoUsr().toString(), persona.getCedulaPersona(),persona.getMail()));



                }
            }

            if (!lstPersonas.isEmpty())
            {

                String abc = lstPersonas.get(0).getNombrePersona().toString();
                if (abc.equals("1"))
                {
                Intent intentAdmin = new Intent(MainActivity.this, Administrador.class);
                startActivity(intentAdmin);
                Toast.makeText(MainActivity.this, "Bienvenido Administrador", Toast.LENGTH_SHORT).show();
                }
                else

                {
                Bundle mBundle = new Bundle();
                //mBundle.putString("user", lstPersonas. user.getEmail());
                String abc1 =TextUtils.join("", new String[]{lstPersonas.get(0).getMail()});
                mBundle.putString("user", abc);
                Intent intent = new Intent(MainActivity.this, MenuActivity.class);
                intent.putExtras(mBundle);
                startActivity(intent);
                //Toast.makeText(MainActivity.this, "Bienvenido " + abc, Toast.LENGTH_SHORT).show();
            }

            }
            else
            {
                Toast.makeText(MainActivity.this, "Usuario No Registrado", Toast.LENGTH_SHORT).show();
                edtPassword.setText("");
            }

        }

    }


}
