package com.example.carwash;

public class Usuario {
    private String nombreCompelto;
    private String correo;
    private String contraseña;
    private int numeroCelular;

    //Constructor para registrarse
    public Usuario(String nombreCompelto, String correo, String contraseña) {
        this.nombreCompelto = nombreCompelto;
        this.correo = correo;
        this.contraseña = contraseña;
        this.numeroCelular = numeroCelular;
    }

    //Contructor para ingresar
    public Usuario(String correo, String contraseña){
        this.correo = correo;
        this.contraseña = contraseña;
    }

    //Constructor para solicitar servicio
    public Usuario(int numeroCelular){
        this.numeroCelular = numeroCelular;
    }
    public String getNombreCompelto() {
        return nombreCompelto;
    }

    public void setNombreCompelto(String nombreCompelto) {
        this.nombreCompelto = nombreCompelto;
    }

    public String getCorreo() {
        return correo;
    }

    public void setCorreo(String correo) {
        this.correo = correo;
    }

    public String getContraseña() {
        return contraseña;
    }

    public void setContraseña(String contraseña) {
        this.contraseña = contraseña;
    }

    public int getNumeroCelular() {
        return numeroCelular;
    }

    public void setNumeroCelular(int numeroCelular) {
        this.numeroCelular = numeroCelular;
    }
}
