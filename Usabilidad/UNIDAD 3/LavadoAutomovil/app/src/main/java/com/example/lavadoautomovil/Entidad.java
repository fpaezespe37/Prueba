package com.example.lavadoautomovil;

import java.io.Serializable;

public class Entidad implements Serializable {



    private int idServicio;
    private int imgFoto;
    private String titulo;
    private String contenido;

    public Entidad(int idServicio, int imgFoto, String titulo, String contenido){
        this.idServicio = idServicio;
        this.imgFoto = imgFoto;
        this.titulo = titulo;
        this.contenido = contenido;
    }

    public int getIdServicio() {
        return idServicio;
    }

    public void setIdServicio(int idServicio) {
        this.idServicio = idServicio;
    }
    public int getImgFoto(){return imgFoto;}

    public String getTitulo(){return titulo;}

    public String getContenido(){return contenido;}

}
