#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED

class archivo_Fecha{

private:
    int dia;
    int mes;
    int anio;

public:
    archivo_Fecha(int d=1, int m=1, int a=1){
    dia=d;
    mes=m;
    anio=a;
    }

    int setDia(int d){
    dia=d;
    }

    int getDia(){
    return dia;
    }

    int setMes(int m){
    mes=m;
    }

    int getMes(){
    return mes;
    }

    int setAnio(int a){
    anio=a;
    }

    int getAnio(){
    return anio;
    }








};

#endif // FECHAS_H_INCLUDED
