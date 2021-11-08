package com.example.lavadoautos;

import java.util.List;

public class Lavado {
    private String tipoLavado;
    private float costoLavado;

    public Lavado(String tipoLavado, float costoLavado) {
        this.tipoLavado = tipoLavado;
        this.costoLavado = costoLavado;
    }

    public String getTipoLavado() {
        return tipoLavado;
    }

    public void setTipoLavado(String tipoLavado) {
        this.tipoLavado = tipoLavado;
    }

    public float getCostoLavado() {
        return costoLavado;
    }

    public void setCostoLavado(float costoLavado) {
        this.costoLavado = costoLavado;
    }
}
