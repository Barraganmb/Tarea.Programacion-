#ifndef OBRAS_H_INCLUDED
#define OBRAS_H_INCLUDED
#include <cstring> // para strcpy
#include "Fechas.h"

class Obras: public archivo_Fecha {
private:
    int idObras;
    char descripcion[40];
    // Asumimos que Fecha está bien definida
    float montoTotal;
    char estadoDeEjecucion[20];
    float pagoAdelantado;
    bool estado;

public:
    Obras(int id = 1, const char* d = "hola", float mT = 0.1, const char* estadoE = "Realizado", float pA = 0.0,
          bool e=false,int di=1, int m=1, int a=1)
    :archivo_Fecha(di, m, a){
    idObras = id;
    strcpy(descripcion, d);
    montoTotal = mT;
    strcpy(estadoDeEjecucion, estadoE);
    pagoAdelantado = pA;
   estado=e;
    }

    void setIdObra(int i) {
        idObras = i;
    }

    int getIdObra() const {
        return idObras;
    }

    void setDescripcion(const char* d) {
        strcpy(descripcion, d);
    }

    const char* getDescripcion() const {
        return descripcion;
    }

    void setMontoTotal(float mT) {
        montoTotal = mT;
    }

    float getMontoTotal() const {
        return montoTotal;
    }

    void setEstadoEjecucion(const char* e) {
        strcpy(estadoDeEjecucion, e);
    }

    const char* getEstadoEjecucion() const {
        return estadoDeEjecucion;
    }

    void setPagoAdelantado(float pA) {
        pagoAdelantado = pA;
    }

    float getPagoAdelantado() const {
        return pagoAdelantado;
    }

    void setEstado(bool e) {
        estado=e;
    }

    bool getEstado() {
        return estado;
    }
};

#endif // OBRAS_H_INCLUDED
