#include <iostream>
#include "ArchivoObras.h"
 using namespace std;
 /**
UNA EMPRESA CONSTRUCTORA TIENE EN SU SISTEMA UN ARCHIVO CON LAS OBRAS REALIZADAS CON LA SIGUIENTE INFORMACION:
-ID DE OBRA (INT)
-DESCRIPCION (CHAR[])
-FECHA OBJ
-MONTO TOTAL
-ESTADO EJECUCION DE LA OBRA (1-PRESUPUESTADO,2-EN EJECUCION,3-FINALIZADA,4-PAUSADA)
-PAGO ADELANTADO
-ESTADO

HACER UN PROGRAMA CON UN NUMERO QUE PERIMTA REALIZAR EL ABML (ALTA, BAJA, MODIFICACION, LISTAR)
DE LOS REGISTROS DEL ARCHIVO CON EL SIGUIENTE FORMATO:
1-ALTA OBRA
2-BAJA OBRA
3-MODIFICACION ESTADO DE EJECUCION
4-LISTAR OBRA
5-INFROMES

EN LA OPCION DE IRFORMES DEBE LLAMARSE A UN SUBMENU QUE REALICE LOS SIGUIENTES INFORMES:
-LISTAR LAS OBRAS DE UN MONTO TOTAL MAYOR AL PROMEDIO PARA LAS OBRAS REALIZADAS EL AÑO PASADO

-LISTAR LAS OBTASD PAUSADAS CUYO PAGO ADELANTADO SEA MAYOR AL 25% DEL MONTO TOTAL DE LA OBRA

-INFROMAR EL MES CON MAYOR CANTIDAD DE OBRAS FINALIZADAS EN TODOS LOS AÑOS
**/

void informes();

int main() {
    int opcion;
    ArchivoObras objObras;
    while(true){

    cout << "---------------------------------------------------"<<endl;
    cout << "-------             Menu ABML              --------"<<endl;
    cout << "---------------------------------------------------"<<endl;
    cout << "-------            1:Alta Obra             --------"<<endl;
    cout << "-------            2:Baja Obra             --------"<<endl;
    cout << "-------            3:Modifcacion Estado    --------"<<endl;
    cout << "-------            4:Listar Obra           --------"<<endl;
    cout << "-------            5:Informes              --------"<<endl;
    cout << "---------------------------------------------------"<<endl;
    cout << "Ingrese Opcion: ";
    cin >> opcion;

    switch (opcion){

    case 1:
    system("cls");
    objObras.altaObra();
    break;

    case 2:
    system("cls");
    objObras.bajaObra();
    break;

    case 3:
    system("cls");
    objObras.modificarEstadoDeEjecucion();
    break;

    case 4:
    system("cls");
    objObras.listarObras();
    break;

    case 5:
    system("cls");
    informes();
    break;

    default:
        return 0;
        break;

    }

    }


return 0; }


void informes(){
ArchivoObras obj;

int opcion;

while(true){
cout<<"                     INFORMES                     "<<endl;
cout<<"--------------------------------------------------------------------"<<endl;
cout<<"1)Obras mayor al promedio que el anio anterior"<<endl;
cout<<"--------------------------------------------------------------------"<<endl;
cout<<"2)Obras pausadas 25%pago adelantado > pago total"<<endl;
cout<<"--------------------------------------------------------------------"<<endl;
cout<<"3)Mes con mayor cantidad de obras finalizadas"<<endl;
cout<<"--------------------------------------------------------------------"<<endl;
cout<<"Ingrese la opcion; ";
cin>>opcion;
}

switch(opcion){

case 1:
    system("cls");
    obj.mayorAlPromedio();
    break;

case 2:
    system("cls");
    obj.obrasPausadas();
    break;

case 3:
    system("cls");
    obj.ObrasFinalizadasXmes();
    break;

default:
    return ;
    break;

}
}
