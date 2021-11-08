package com.example.lavadoautomovil.Clases;

import org.ksoap2.serialization.KvmSerializable;
import org.ksoap2.serialization.PropertyInfo;
import org.ksoap2.serialization.SoapObject;

import java.util.Hashtable;

import Clases.Deserealiza;

public class EReservas1 implements KvmSerializable {

    Integer IdReserva;
    String CedulaPersona;
    Integer IdServicio;
    String Fecha;
    Boolean Cancelado;
    String Observacion;
    Boolean RegistroNuevo;
    String Hora;
    Integer TipoBusqueda;
    String NombreTipoServicio;


    public Integer getIdReserva() {
        return IdReserva;
    }

    public void setIdReserva(Integer idReserva) {
        IdReserva = idReserva;
    }

    public String getCedulaPersona() {
        return CedulaPersona;
    }

    public void setCedulaPersona(String cedulaPersona) {
        CedulaPersona = cedulaPersona;
    }

    public Integer getIdServicio() {
        return IdServicio;
    }

    public void setIdServicio(Integer idServicio) {
        IdServicio = idServicio;
    }

    public String getFecha() {
        return Fecha;
    }

    public void setFecha(String fechaReservacionServicio) {
        Fecha = fechaReservacionServicio;
    }

    public Boolean getCancelado() {
        return Cancelado;
    }

    public void setCancelado(Boolean cancelado) {
        Cancelado = cancelado;
    }

    public String getObservacion() {
        return Observacion;
    }

    public void setObservacion(String observacion) {
        Observacion = observacion;
    }

    public Boolean getRegistroNuevo() {
        return RegistroNuevo;
    }

    public void setRegistroNuevo(Boolean registroNuevo) {
        RegistroNuevo = registroNuevo;
    }

    public String getHora() {
        return Hora;
    }

    public void setHora(String hora) {
        Hora = hora;
    }

    public Integer getTipoBusqueda() {
        return TipoBusqueda;
    }

    public void setTipoBusqueda(Integer tipoBusqueda) {
        TipoBusqueda = tipoBusqueda;
    }

    public String getNombreTipoServicio() {
        return NombreTipoServicio;
    }

    public void setNombreTipoServicio(String nombreTipoServicio) {
        NombreTipoServicio = nombreTipoServicio;
    }

    public EReservas1()
    {

    }

    public EReservas1(Integer idReserva, String cedulaPersona, Integer idServicio, String fechaReservacionServicio, Boolean cancelado, String observacion, Boolean registroNuevo, String hora,
                      Integer tipoBusqueda) {
        IdReserva = idReserva;
        CedulaPersona = cedulaPersona;
        IdServicio = idServicio;
        Fecha = fechaReservacionServicio;
        Cancelado = cancelado;
        Observacion = observacion;
        RegistroNuevo = registroNuevo;
        Hora = hora;
        TipoBusqueda = tipoBusqueda;
    }

    public EReservas1(Integer idReserva, String cedulaPersona, String nombreServicio, String fechaReservacionServicio) {
        IdReserva = idReserva;
        CedulaPersona = cedulaPersona;
        NombreTipoServicio = nombreServicio;
        Fecha = fechaReservacionServicio;
    }

    public EReservas1(SoapObject object) {
        new Deserealiza().SoapDeserealize(this, object);
    }




    @Override
    public Object getProperty(int arg0) {
        switch (arg0) {
            case 0:
                return this.IdReserva;
            case 1:
                return this.CedulaPersona;
            case 2:
                return this.IdServicio;
            case 3:
                return this.Fecha;
            case 4:
                return this.Cancelado;
            case 5:
                return this.Observacion;
            case 6:
                return this.RegistroNuevo;
            case 7:
                return this.Hora;
            case 8:
                return this.TipoBusqueda;
            case 9:
                return this.NombreTipoServicio;

        }
        return null;
    }



    @Override
    public int getPropertyCount() {
        return 10;
    }

    @Override
    public void setProperty(int indice, Object val) {
        switch (indice) {
            case 0:
                IdReserva = Integer.parseInt((val.toString()));
                break;

            case 1:
                CedulaPersona = (val.toString());
                break;
            case 2:
                IdServicio = Integer.parseInt((val.toString()));
                break;

            case 3:
                Fecha = val.toString();
                //FechaReservacionServicio = new Date(Date.parse(val.toString()));
                //FechaReservacionServicio = new Date((val.toString()));

                break;

            case 4:
                Cancelado = Boolean.parseBoolean(val.toString());
                break;
            case 5:
                Observacion = (val.toString());
                break;
            case 6:
                RegistroNuevo = Boolean.parseBoolean(val.toString());
                break;
            case 7:
                Hora = (val.toString());
                break;
            case 8:
                TipoBusqueda = Integer.parseInt(val.toString());
                break;
            case 9:
                NombreTipoServicio = (val.toString());
                break;
            default:
                break;
        }
    }



    @Override
    public void getPropertyInfo(int indice, Hashtable hashtable, PropertyInfo info) {
        switch (indice) {
            case 0:
                info.type = PropertyInfo.INTEGER_CLASS;
                info.name = "IdReserva";
                break;

            case 1:
                info.type = PropertyInfo.STRING_CLASS;
                info.name = "CedulaPersona";
                break;
            case 2:
                info.type = PropertyInfo.INTEGER_CLASS;
                info.name = "IdServicio";
                break;

            case 3:
                //info.type = Date.class;
                info.type = PropertyInfo.STRING_CLASS;
                info.name = "Fecha";
                break;

            case 4:
                info.type = PropertyInfo.INTEGER_CLASS;
                info.name = "Cancelado";
                break;
            case 5:
                info.type = PropertyInfo.STRING_CLASS;
                info.name = "Observacion";
                break;
            case 6:
                info.type = PropertyInfo.INTEGER_CLASS;
                info.name = "RegistroNuevo";
                break;
            case 7:
                info.type = PropertyInfo.STRING_CLASS;
                info.name = "Hora";
                break;
            case 8:
                info.type = PropertyInfo.INTEGER_CLASS;
                info.name = "TipoBusqueda";
                break;
            case 9:
                //info.type = Date.class;
                info.type = PropertyInfo.STRING_CLASS;
                info.name = "NombreTipoServicio";
                break;
            default:
                break;
        }
    }
}

