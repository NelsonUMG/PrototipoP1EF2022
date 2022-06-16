#include "MenuGeneral.h"
#include <iostream>
#include<conio.h>
#include "Persona.h"
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ios;
using std::left;
using std::right;
using std::fixed;
using std::showpoint;

#include <ctime>
#include <vector>
#include <fstream>

using std::ofstream;
using std::ostream;
using std::fstream;

#include <iomanip>

using std::setw;
using std::setprecision;

#include <cstdlib>
using namespace std;
MenuGeneral::menuGeneral()
{
MenuGeneral menuG;
int choice;
	char x;
	do
    {
	system("cls");
	//Funcion que imprime Fecha  y Hora
	cout<<"\t\t\t ***  Bienvenido a Laboratorio Clinico *** "<<endl;
	cout<<"\t\t\t  9959-21-10015 NELSON JOSUE PINEDA CULAJAY "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Gestiones de empleado"<<endl;
	cout<<"\t\t\t 2. Gestiones de paciente"<<endl;
	cout<<"\t\t\t 3. Pagar Cuenta"<<endl;
	cout<<"\t\t\t 4. Consulta de empleados"<<endl;
	cout<<"\t\t\t 5. Consulta de pacientes"<<endl;
	cout<<"\t\t\t 6. Consulta de cuenta de pago del paciente"<<endl;
	cout<<"\t\t\t 7. Asignacion de citas"<<endl;
	cout<<"\t\t\t 8. Transferencias de Banco"<<endl;
	cout<<"\t\t\t 9. Salir"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6/7/8]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;
//Llamadas a los menus secundarios
    switch(choice)
    {
    case 1:
        menuEmpleados();
		break;
	case 2:
		break;
	case 3:
        break;
    case 4:
		break;

    case 5:

	case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
	default:
		cout<<"\n\t\t\t Opción incorrecta, seleccione de nuevo";
	}
    }while(choice!= 9);
    return 0;
}
MenuGeneral::menuEmpleados()
{
    Persona empleado;

    fstream empleadosEntradaSalida = empleado.inicioArchivo();
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t    GESTION EMPLEADOS    "<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t 1. Consulta Empleados"<<endl;
	cout<<"\t\t\t 2. Busqueda de Empleados"<<endl;
	cout<<"\t\t\t 3. Agregar Empleados"<<endl;
	cout<<"\t\t\t 4. Modificar Empleados"<<endl;
	cout<<"\t\t\t 5. Eliminar Empleados"<<endl;
	cout<<"\t\t\t 6. Imprimir Archivo Empleados"<<endl;
	cout<<"\t\t\t 7. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6/7]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa una Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        empleado.consultarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 2:
        empleado.busquedaRegistro(empleadosEntradaSalida);
		break;
	case 3:
        empleado.nuevoRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado agregado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 4:

        empleado.actualizarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado modificado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 5:

        empleado.eliminarRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Empleado eliminado satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
    case 6:
        empleado.imprimirRegistro(empleadosEntradaSalida);
        cout << "" << endl;
        cout<<"Informacion impresa satisfactoriamente"<<endl;
        cout << "" << endl;
        cout << "Presiona enter para continuar" << endl;
		break;
	case 7:
	        cout<<"Presione Enter para confirmar"<<endl;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	empleadosEntradaSalida.clear(); // reinicializar indicador de fin de archivo
    getch();
    }while(choice!= 7);
}
