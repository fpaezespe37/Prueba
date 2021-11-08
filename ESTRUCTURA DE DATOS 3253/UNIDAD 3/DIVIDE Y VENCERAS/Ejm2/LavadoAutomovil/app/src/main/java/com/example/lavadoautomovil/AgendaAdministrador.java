package com.example.lavadoautomovil;

import androidx.appcompat.app.AppCompatActivity;

import android.app.AlertDialog;
import android.app.ProgressDialog;
import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
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

public class AgendaAdministrador extends AppCompatActivity {

    String namespace;
    String url;
    String methodName;

    Button btnConfirmar, btn_rechazar, btn_listo;
    private TextView txtinput_fecha, txtinput_hora,txtinput_telefono,txtinput_ubicacion;
    private ArrayList<Entidad> arrayentidad;

    private ListView listview;
    private ArrayList<EReservas> listReservas;
    private List<EReservas> listViwReservas;

    private ArrayList<String> names;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
            super.onCreate(savedInstanceState);
            setContentView(R.layout.activity_agenda_administrador);
            btn_listo = findViewById(R.id.btn_listo);
            btnConfirmar = (Button)findViewById(R.id.btnConfirmar);
            listview = (ListView) findViewById(R.id.lstReservas);

            names = new ArrayList<String>();

        /*names.add("nombres");
        names.add("Tabasco");
        names.add("Chiapas");
        names.add("Campeche");
        names.add("Quintana Roo");
*/
            consultawsBuscaReservas("BuscarReservas");
            /*
            ArrayAdapter<EReservas> adapter = new ArrayAdapter<EReservas>(this, android.R.layout.simple_list_item_1, listReservas);

            listview.setAdapter(adapter);
*/



        /*String fecha, hora, telefono, ubicacion;
        Intent intent = getIntent();
        Bundle extras = intent.getExtras();
        fecha = extras.getString("Fecha");
        hora = extras.getString("Hora");
        telefono = extras.getString("Telefono");
        ubicacion = extras.getString("Direccion");

        txtinput_fecha.setText(fecha);
        txtinput_hora.setText(hora);
        txtinput_telefono.setText(telefono);
        txtinput_ubicacion.setText(ubicacion);*/


            btnConfirmar.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {

                    ArrayAdapter<String> adapter = new ArrayAdapter<String>(AgendaAdministrador.this, android.R.layout.simple_list_item_1, names);
                    //ArrayAdapter<EReservas> adapter = new ArrayAdapter<EReservas>(AgendaAdministrador.this, android.R.layout.simple_list_item_1, listViwReservas);
                    listview.setAdapter(adapter);

                    /*
                    Intent intent = new Intent(AgendaAdministrador.this, Finaladmi.class);

                    startActivity(intent);*/
                }
            });

        btn_listo.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(AgendaAdministrador.this, Finaladmi.class);
                startActivity(intent);
            }
        });
                }

    private void consultawsBuscaReservas(String MetodoEjecutar )
    {
        //EjecutaBarraProgreso();
        AsyncCallWSBuscaReservas task = new AsyncCallWSBuscaReservas();
        task.execute("BuscarReserva");
    }

    public void CargarLista(ArrayList<EReservas> listaReservasLocal)
    {
        listReservas = listaReservasLocal;

    }

    //LLAMDAS AL WS SERBVICE

    private class AsyncCallWSBuscaReservas  extends AsyncTask<String, Void, ArrayList<EReservas>> {

        ProgressDialog pDialog;

        @Override
        protected void onPreExecute() {

            pDialog = new ProgressDialog(AgendaAdministrador.this);
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

            Map<String, String> listParams = new HashMap<String, String>();


// INSERTA RESERVAS
            listParams.put("IdReserva", "0");
            listParams.put("IdServicio", "0");
            listParams.put("CedulaPersona", "1713");
            listParams.put("TipoBusqueda","0");
            listParams.put("Observacion","");
            listParams.put("Cancelado","false");
            listParams.put("RegistroNuevo","true");
            listParams.put("Fecha","");
            listParams.put("Hora","");
            listParams.put("Telefono","");
            listParams.put("Direccion","");


            wsServicios wsServicios = new wsServicios(namespace,url,methodName,listParams);
            try {
                switch (params[0]) {
                    case "BuscarServicios":
                        //respuestaWS = new wsServicios(namespace,url,methodName,listParams).consultarServiciosActivos();
                        break;
                    case  "BuscarReserva":
                        //consultarReserva(listParams);
                        listReservas = new wsServicios(namespace,url,methodName,listParams).consultarReserva();
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
                String x = resultado;
            }

            return  listReservas;
        }

        @Override
        protected void onPostExecute(ArrayList<EReservas> respuestaWSVerificaImei) {
            AlertDialog.Builder dialogo = new AlertDialog.Builder(AgendaAdministrador.this);
            ArrayList<EReservas> listReservasLocal = null;

            pDialog.dismiss();
            try {
                for (EReservas persona : respuestaWSVerificaImei) {
                    //clave = categoria.getNombreCategoria();
                    if (persona.getIdServicio() != null ) {
                        //lstCategorias.add(new EPersona(categoria.getIdServicio(), categoria.getNombreServicio(),categoria.getPrecioServicio()));
                        //lstPersonas.add(new EPersona(persona.getNombrePersona(), persona.getCedulaPersona(),persona.getMail()));
                        names.add(persona.getNombreTipoServicio().toString() +" "+ persona.getTelefono().toString()+" "+ persona.getDireccion().toString() + " "
                                + persona.getFecha().toString()+" "+ persona.getHora().toString()+" "+persona.getObservacion().toString());

 //                       listReservasLocal.add(new EReservas(persona.getIdReserva(), persona.getNombreTipoServicio(), persona.getTelefono(),persona.getDireccion(),
   //                             persona.getFecha(),persona.getHora(),persona.getObservacion()));

                    }
            }

                listReservas = respuestaWSVerificaImei;
            }
            catch (Exception ex)
            {
                String error = ex.getMessage();
            }


            if (!listReservas.isEmpty())
            {

               String G = "2"; //;String abc = lstPersonas.get(0).getNombrePersona().toString();

            }
            else
            {
                Toast.makeText(AgendaAdministrador.this, "NO HAY RESERVAS DISPONIBLES", Toast.LENGTH_SHORT).show();
            }

        }

    }



}