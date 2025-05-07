#include <iostream>
#include "Obras.h"
using namespace std;

class ArchivoObras{

public:
void altaObra();
int idUnico();
void bajaObra();
void modificarEstadoDeEjecucion();
void listarObras();

};

void ArchivoObras::altaObra(){
FILE *alta;

alta=fopen("Obras.dat","wb");
if(alta==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return;
}

Obras obj;

ArchivoObras obj1;

int idO, anio,mes,dia, opcion;
float total, pagoAdelantado;
char descripcion[40];
char estadoDeEjecucion[20];
bool estado= false;

cout<<"DAR ALTA NUEVA OBRA"<<endl;

idO=obj1.idUnico();
cout<<"El id Asignado a esta obra es: "<<idO<<endl;
obj.setIdObra(idO);

cout<<"Descripcion de la obra: ";
cin.getline(descripcion,40,'\n');
obj.setDescripcion(descripcion);

cout<<"Ingrese la fecha: "<<endl;
cout<<"Anio: ";
cin>>anio;
obj.setAnio(anio);
cout<<endl;

cout<<"Mes: ";
cin>>mes;
obj.setMes(mes);
cout<<endl;

cout<<"Dia: ";
cin>>dia;
obj.setDia(dia);
cout<<endl;

cout<<"Ingrese el monto total de la obra: ";
cin>>total;
obj.setMontoTotal(total);

cout<<"Estado de ejecucion de la obra: "<<endl;
cout<<"1)Presupuestado"<<endl;
cout<<"2)En ejecucion"<<endl;
cout<<"3)Finalizada"<<endl;
cout<<"4)Pausada"<<endl;

cin>>opcion;
switch(opcion){
case 1: strcpy(estadoDeEjecucion, "Presupuestado");
break;

case 2: strcpy(estadoDeEjecucion, "En ejecucion");
break;

case 3: strcpy(estadoDeEjecucion, "Finalizada");
break;

case 4: strcpy(estadoDeEjecucion, "Pausada");
break;

default: strcpy(estadoDeEjecucion, "Desconocido");
break;
}

obj.setEstadoEjecucion(estadoDeEjecucion);

cout<<"Ingrese el total del pago adelantado: ";
cin>>pagoAdelantado;
obj.setPagoAdelantado(pagoAdelantado);

estado=true;
obj.setEstado(estado);

fwrite(&obj, sizeof(Obras), 1, alta);
fclose(alta);

}

int ArchivoObras::idUnico(){
FILE* id;
id=fopen("Obras.dat", "rb+");
if(id==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return 0;
}
Obras obj;
int idObras;
while(fread(&obj, sizeof(Obras),1,id)==1){
if (obj.getIdObra() > idObras) {
idObras = obj.getIdObra();
}
return idObras+1;
}
}


void ArchivoObras::bajaObra(){
FILE *baja;
baja=fopen("Obras.dat","rb+");
if(baja==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return ;
}

Obras obj;
int id;
bool estado=true;
long posicion = ftell(baja);
cout<<"DAR DE BAJA OBRA"<<endl;

cout<<"Ingrese el id de la obra que quiere dar de baja:  ";
cin>>id;

while(fread(&obj,sizeof(Obras),1,baja)==1){

if(obj.getIdObra()==id){
estado=false;
obj.setEstado(estado);
fseek(baja, posicion, SEEK_SET);
fwrite(&obj, sizeof(Obras), 1, baja);
}

else {
cout<<"El id ingresado no se encontro"<<endl;
return;
}

}
fclose(baja);
}


void ArchivoObras::modificarEstadoDeEjecucion(){
FILE *modificar;
modificar=fopen("Obras.dat","rb+");
if(modificar==NULL){
cout<<"No se logro abrir este archivo"<<endl;
return;
}

Obras obj;
int id, opcion;
char estadoDeEjecucion[20];
long posicion = ftell(modificar);

cout<<"MODIFICAR ESTADO DE EJECUCION"<<endl;
cout<<"Ingrese el id de la bra que quiere modificar: ";
cin>>id;

while(fread(&obj,sizeof(Obras),1,modificar)==1){
if(obj.getIdObra()==id){
cout<<"Estado de ejecucion de la obra: "<<endl;
cout<<"1)Presupuestado"<<endl;
cout<<"2)En ejecucion"<<endl;
cout<<"3)Finalizada"<<endl;
cout<<"4)Pausada"<<endl;

cin>>opcion;
switch(opcion){
case 1: strcpy(estadoDeEjecucion, "Presupuestado");
break;

case 2: strcpy(estadoDeEjecucion, "En ejecucion");
break;

case 3: strcpy(estadoDeEjecucion, "Finalizada");
break;

case 4: strcpy(estadoDeEjecucion, "Pausada");
break;

default: strcpy(estadoDeEjecucion, "Desconocido");
break;
}

obj.setEstadoEjecucion(estadoDeEjecucion);

fseek(modificar, posicion, SEEK_SET);
fwrite(&obj, sizeof(Obras), 1, modificar);

}
}
fclose(modificar);
}


void ArchivoObras::listarObras(){
FILE *listar;
listar=fopen("Obras.dat","rb");
if(listar==NULL){
cout<<"No se logro abrir el archivo"<<endl;
return;
}

Obras obj;
cout<<"Listar Obras"<<endl;
while(fread(&obj,sizeof(Obras),1,listar)==1){
cout<<"Id: "<<obj.getIdObra()<<endl;
cout<<"Descripcion: "<<obj.getDescripcion()<<endl;
cout<<"Fecha: "<<obj.getAnio()<<" / "<<obj.getMes()<<" / "<<obj.getDia()<<endl;

cout<<"Monto total: "<<obj.getMontoTotal()<<endl;
cout<<"Estado de ejecucion de la obra: "<<obj.getEstadoEjecucion()<<endl;
cout<<"Pago adelantado: $"<<obj.getPagoAdelantado()<<endl;
cout<<"-------------------------------------------------------------------------"<<endl;
}
fclose(listar);
}
