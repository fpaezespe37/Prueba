package com.example.lavadoautomovil;

import androidx.appcompat.app.AppCompatActivity;

import android.app.DatePickerDialog;
import android.app.TimePickerDialog;
import android.content.Intent;
import android.media.MediaParser;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.Spinner;
import android.widget.TimePicker;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.GregorianCalendar;


public class Agendar extends AppCompatActivity implements View.OnClickListener, AdapterView.OnItemSelectedListener {

    private ArrayList<CountryItem> mCountryList;
    private CountryAdapter mAdapter;

    Button btfecha, bthora, btmapa;
    EditText edtfecha, edthora, txt_number, txt_direccion;
    private int dia, mes, anio, hora, min;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_agendar);
        /*initList();
        Spinner spinnerCountries = findViewById(R.id.spinner_countries);
        mAdapter = new CountryAdapter(this, mCountryList);
        spinnerCountries.setAdapter(mAdapter);

        spinnerCountries.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                CountryItem clickedItem = (CountryItem) parent.getItemAtPosition(position);
                String clickedCountryName = clickedItem.getCountryName();
                Toast.makeText(Agendar.this, clickedCountryName + " selected", Toast.LENGTH_SHORT).show();
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });*/
        btfecha = (Button) findViewById(R.id.btn_fecha);
        bthora = (Button) findViewById(R.id.btn_hora);
        edtfecha = (EditText) findViewById(R.id.edttxt_fecha);
        txt_number = findViewById(R.id.txt_number);
        txt_direccion = findViewById(R.id.txt_direccion);
        //edthora = (EditText) findViewById(R.id.edttxt_hora);
        btfecha.setOnClickListener(this);
        bthora.setOnClickListener(this);
        Spinner spinner = findViewById(R.id.spinner1);
        ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(this, R.array.hours, android.R.layout.simple_spinner_item);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spinner.setAdapter(adapter);
        spinner.setOnItemSelectedListener(this);

        btmapa = (Button) findViewById(R.id.btn_irmapa);
        btmapa.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String spin,spin1,spin2,spin3,spin4;
                spin = edtfecha.getText().toString().trim();
                spin1 = spinner.getSelectedItem().toString().trim();
                spin2 = txt_number.getText().toString().trim();
                spin3 = txt_direccion.getText().toString().trim();
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
                Intent intent = new Intent(Agendar.this, Tiposlavado.class);
                intent.putExtras(extras);
                startActivity(intent);
            }
        });
    }


    private void initList() {
        mCountryList = new ArrayList<>();
        mCountryList.add(new CountryItem("Automóvil + Completo", R.drawable.img_camioneta));
        mCountryList.add(new CountryItem("Automóvil + Express", R.drawable.img_camioneta));
        mCountryList.add(new CountryItem("Camioneta + Completo", R.drawable.img_car));
        mCountryList.add(new CountryItem("Camioneta + Express ", R.drawable.img_car));
    }

    @Override
    public void onClick(View v) {
        if (v == btfecha) {
            final Calendar c = Calendar.getInstance();
            dia = c.get(Calendar.DAY_OF_MONTH);
            mes = c.get(Calendar.MONTH);
            anio = c.get(Calendar.YEAR);
            DatePickerDialog oyenteSelectorFecha = new DatePickerDialog(this, new DatePickerDialog.OnDateSetListener() {
                @Override
                public void onDateSet(DatePicker view, int year, int monthOfYear, int dayOfMonth) {
                    Log.i("TAG", String.valueOf(year) + String.valueOf(monthOfYear) + String.valueOf(dayOfMonth));
                    edtfecha.setText(dayOfMonth + "/" + (monthOfYear + 1) + "/" + year);
                }
            }, dia, mes, anio);
            Calendar calendarioMin = Calendar.getInstance();
            calendarioMin.add(Calendar.MONTH, - 1);
            calendarioMin.add(Calendar.DAY_OF_MONTH, - 1);
            oyenteSelectorFecha.getDatePicker().setMinDate(calendarioMin.getTimeInMillis() - 1000);
            oyenteSelectorFecha.show();
        }
    }

        /*if(v==bthora){
            final Calendar c = Calendar.getInstance();
             hora = c.get(Calendar.HOUR_OF_DAY);
             min = c.get(Calendar.MINUTE);
            TimePickerDialog timePickerDialog = new TimePickerDialog(this, new TimePickerDialog.OnTimeSetListener() {
                @Override
                public void onTimeSet(TimePicker view, int hourOfDay, int minute) {
                    edthora.setText(hourOfDay + ":" + minute);

                }
            },hora, min,false);
            timePickerDialog.show();

        }*/


    @Override
    public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
        String text = parent.getItemAtPosition(position).toString();
        Toast.makeText(parent.getContext(), text, Toast.LENGTH_SHORT).show();

    }

    @Override
    public void onNothingSelected(AdapterView<?> parent) {

    }
}