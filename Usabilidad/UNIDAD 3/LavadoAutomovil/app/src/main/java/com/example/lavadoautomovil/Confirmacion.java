package com.example.lavadoautomovil;

import androidx.appcompat.app.AppCompatActivity;

import android.app.AlertDialog;
import android.app.ProgressDialog;
import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import com.freddypaez.carwashdll.wsServicios;

import java.security.CodeSigner;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import Clases.EPersona;
import Clases.EReservas;

public class Confirmacion extends AppCompatActivity {

    String namespace;
    String url;
    String methodName;
    Integer IdServicio;
    private Entidad Item;
    private TextView titulo, descripcion;
    private ImageView imgFoto;
    private Button btn_confirmar;
    TextView txt_hora,txt_tipos;
    private TextView fech, hor, telef, direccion;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_confirmacion);
        Item = (Entidad) getIntent().getSerializableExtra("ObjetoData");

        titulo = findViewById(R.id.txt_prueba);
        descripcion = findViewById(R.id.Descrp);
        imgFoto = findViewById(R.id.ImgFoto);
        btn_confirmar = findViewById(R.id.btn_conf);
        fech = findViewById(R.id.textView26);
        hor = findViewById(R.id.textView27);
        telef = findViewById(R.id.textView28);
        direccion = findViewById(R.id.textView29);
        titulo.setText(Item.getTitulo());
        imgFoto.setImageResource(Item.getImgFoto());
        descripcion.setText(Item.getContenido());
        IdServicio = Item.getIdServicio();
        String fecha, hora, telefono, ubicacion;
        Intent intent = getIntent();
        Bundle extras = intent.getExtras();
        fecha = extras.getString("Fecha");
        hora = extras.getString("Hora");
        telefono = extras.getString("Telefono");
        ubicacion = extras.getString("Direccion");

        fech.setText(fecha);
        hor.setText(hora);
        telef.setText(telefono);
        direccion.setText(ubicacion);

        btn_confirmar.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                String spin,spin1,spin2,spin3,spin4;
                spin = fech.getText().toString().trim();
                spin1 = hor.getText().toString().trim();
                spin2 = telef.getText().toString().trim();
                spin3 = direccion.getText().toString().trim();
                // spin4 = spinner.getSelectedItem().toString().trim();


                //spin2 = edtfecha.getText().toString().trim();
                //tipos = spinnerCountries.getSelectedItem().toString().trim();
                Bundle extras = new Bundle();
                extras.putString("Fecha", spin);
                extras.putString("Hora", spin1);
                extras.putString("Telefono", spin2);
                extras.putString("Direccion", spin3);
                //extras.putString("Tipo Lavado", tipos);
                //extras
                Intent intent = new Intent(Confirmacion.this, Final.class);
                intent.putExtras(extras);
                startActivity(intent);
                IngresaCitas("InsertaReserva");
            }
        });

    }

    private void IngresaCitas(String MetodoEjecutar )
    {
        //EjecutaBarraProgreso();
        AsyncCallWSIngresaCitas task = new AsyncCallWSIngresaCitas();
        //task.execute("BuscarServicios");
        task.execute("InsertaReserva");
        //task.execute("BuscarReserva");
    }

    //LLAMDAS AL WS SERBVICE

    private class AsyncCallWSIngresaCitas extends AsyncTask<String, Void, ArrayList<EReservas>> {

        ProgressDialog pDialog;

        @Override
        protected void onPreExecute() {
            pDialog = new ProgressDialog(Confirmacion.this);
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

            // INSERTA RESERVAS
            listParams.put("IdReserva", "0");
            listParams.put("IdServicio", IdServicio.toString());
            listParams.put("CedulaPersona", "1713");
            listParams.put("TipoBusqueda","0");
            listParams.put("Observacion",descripcion.getText().toString());
            listParams.put("Cancelado","false");
            listParams.put("RegistroNuevo","true");
            listParams.put("Fecha",fech.getText().toString());
            listParams.put("Hora",hor.getText().toString());
            listParams.put("Telefono",telef.getText().toString());
            listParams.put("Direccion",direccion.getText().toString());

//            titulo


            wsServicios wsServicios = new wsServicios(namespace,url,methodName,listParams);
            try {
                switch (params[0]) {
                    case "BuscarServicios":
                        //respuestaWS = new wsServicios(namespace,url,methodName,listParams).consultarServiciosActivos();
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
            AlertDialog.Builder dialogo = new AlertDialog.Builder(Confirmacion.this);

            pDialog.dismiss();
            List<EReservas> lstPersonas = new ArrayList<EReservas>();
            for (EReservas persona : respuestaWSVerificaImei) {
                //clave = categoria.getNombreCategoria();
                if (persona.getIdReserva() != null ) {
                    //lstCategorias.add(new EPersona(categoria.getIdServicio(), categoria.getNombreServicio(),categoria.getPrecioServicio()));
                    lstPersonas.add(new EReservas(persona.getIdReserva(), persona.getNombreTipoServicio(), persona.getTelefono(),persona.getDireccion(),persona.getFecha(),persona.getHora(),persona.getObservacion()));
                }
            }

            if (!lstPersonas.isEmpty())
            {
                ;
            }
        }

    }
}