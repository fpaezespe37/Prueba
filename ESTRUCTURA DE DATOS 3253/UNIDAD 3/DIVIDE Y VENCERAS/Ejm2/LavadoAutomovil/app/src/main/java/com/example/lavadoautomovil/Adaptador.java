package com.example.lavadoautomovil;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.ArrayList;

public class Adaptador extends BaseAdapter {
    private Context context;
    private ArrayList<Entidad> listItems;

    public Adaptador(Context context, ArrayList<Entidad> listItems) {
        this.context = context;
        this.listItems = listItems;
    }

    @Override
    public int getCount() {
        return listItems.size();
    }

    @Override
    public Object getItem(int position) {
        return listItems.get(position);
    }

    @Override
    public long getItemId(int position) {
        return 0;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        Entidad Item = (Entidad) getItem(position);


        convertView = LayoutInflater.from(context).inflate(R.layout.activity_lavados, null);
        ImageView imgFoto = convertView.findViewById(R.id.ImgFoto);
        TextView textView = convertView.findViewById(R.id.Titulo);
        TextView textView1 = convertView.findViewById(R.id.Contenido);

        imgFoto.setImageResource(Item.getImgFoto());

        textView.setText(Item.getTitulo());

        textView1.setText(Item.getContenido());


        return convertView;
    }
}
