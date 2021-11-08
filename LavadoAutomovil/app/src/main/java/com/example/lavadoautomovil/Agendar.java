package com.example.lavadoautomovil;

import androidx.appcompat.app.AppCompatActivity;

import android.app.DatePickerDialog;
import android.app.TimePickerDialog;
import android.content.Intent;
import android.media.MediaParser;
import android.os.Bundle;
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

public class Agendar extends AppCompatActivity implements View.OnClickListener, AdapterView.OnItemSelectedListener {

    private ArrayList<CountryItem> mCountryList;
    private CountryAdapter mAdapter;

    Button btfecha, bthora, btmapa;
    EditText edtfecha, edthora;
    private int dia, mes, anio, hora, min;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_agendar);
        initList();
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
        });
        btfecha = (Button) findViewById(R.id.btn_fecha);
        bthora = (Button) findViewById(R.id.btn_hora);
        edtfecha = (EditText) findViewById(R.id.edttxt_fecha);
        //edthora = (EditText) findViewById(R.id.edttxt_hora);
        btfecha.setOnClickListener(this);
        bthora.setOnClickListener(this);
        Spinner spinner = findViewById(R.id.spinner1);
        ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(this, R.array.hours, android.R.layout.simple_spinner_item);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spinner.setAdapter(adapter);
        spinner.setOnItemSelectedListener(this);

        btmapa = (Button)findViewById(R.id.btn_irmapa);
        btmapa.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(Agendar.this, Datos.class);
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
        if (v==btfecha){
            final Calendar c = Calendar.getInstance();
            dia = c.get(Calendar.DAY_OF_MONTH);
            mes = c.get(Calendar.MONTH);
            anio = c.get(Calendar.YEAR);

            if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.N) {
                DatePickerDialog datePickerDialog = new DatePickerDialog(this, new DatePickerDialog.OnDateSetListener() {
                    @Override
                    public void onDateSet(DatePicker view, int year, int monthOfYear, int dayOfMonth) {
                        edtfecha.setText(dayOfMonth + "/" + (monthOfYear+1) + "/" + year);



                    }
                }
                , dia,mes,anio);
                datePickerDialog.show();
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
    }

    @Override
    public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
        String text = parent.getItemAtPosition(position).toString();
        Toast.makeText(parent.getContext(), text, Toast.LENGTH_SHORT).show();

    }

    @Override
    public void onNothingSelected(AdapterView<?> parent) {

    }
}