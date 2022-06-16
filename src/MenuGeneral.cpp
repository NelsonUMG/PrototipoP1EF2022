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
Persona gesPersona;

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
        gesPersona.menu();
		break;
	case 2:
	    gesPersona.menu2();
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
