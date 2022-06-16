#include "MenuGeneral.h"
#include "Persona.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>


//Mantenimiento de Departamentos y Puestos - Maria Jose Veliz 9959-21-5909
//menu principal de puestos
void Persona::menu()
{

    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t................................"<<endl;
	cout<<"\t\t\t .  Gestion de empleados   ."<<endl;
	cout<<"\t\t\t................................"<<endl;
	cout<<"\t\t\t 1. Ingreso Empleado"<<endl;
	cout<<"\t\t\t 2. Actualizar empleado"<<endl;
	cout<<"\t\t\t 3. Consultar empleado"<<endl;
	cout<<"\t\t\t 4. Imprimir empleado"<<endl;
	cout<<"\t\t\t 5. Borrar empleado"<<endl;
	cout<<"\t\t\t 6. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t Opcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{

    		Ingresar();
    		cout<<"\n\t\t\t Agrega otro Empleado(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		cout <<"Empleado agregados satisfactoriamente"<<endl;
		break;
	case 2:

		Actualizar();
		cout <<"Empleadoactualizado satisfactoriamente"<<endl;
		break;
	case 3:

		Consultar();
		cout <<"Presiona Enter para salir"<<endl;
		break;
	case 4:

		Imprimir();
		cout <<"Impresion realizada satisfactoriamente"<<endl;
		break;
	case 5:

		Borrar();
		cout <<"Empleado eliminado satisfactoriamente"<<endl;
		break;
	case 6:
	    cout << "Presiona Enter para confirmar"<<endl;
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 6);
}


//Funcion que ingresa puestos y departamentos
void Persona::Ingresar()
{

	system("cls");
	fstream file;
	cout<<"\n.....................................................................................................................";
	cout<<"\n.....................................Agregar detalles de Empleado......................................................"<<endl;
	cout<<"\t\t\tIngresa el ID del empleado: ";
	cin>>ID;
	cout<<"\t\t\tIngresa el Apellido     : ";
	cin>>AAPELLIDO;
	cout<<"\t\t\tIngresa Nombre  : ";
	cin>>NNOMBRE;
	cout<<"\t\t\tIngresa No. Telefono : ";
	cin>>TTELEFONO;
	cout<<"\t\t\tIngresa DPI  : ";
	cin>>DDPI;
	cout<<"\t\t\tIngresa Direccion  : ";
	cin>>DDIRECCION;
	cout<<"\t\t\tIngresa la Fecha  : ";
	cin>>FFECHA;
	cout<<"\t\t\tIngresa la identificacion de usuario : ";
	cin>>IIDUSER;
	file.open("PUESTO.dat", ios::out | ios::binary);
	file<<std::left<<std::setw(15)<<ID<<std::left<<std::setw(15)<<AAPELLIDO<<std::left<<std::setw(15)<<NNOMBRE <<std::left<<std::setw(15)<<TTELEFONO<<std::left<<std::setw(15)<<FFECHA<<std::left<<std::setw(15)<<DDPI<<std::left<<std::setw(15)<<DDIRECCION<<std::left<<std::setw(15)<<IIDUSER << "\n";
	file.close();
    file.open("PUESTO.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<<ID<<std::left<<std::setw(15)<<AAPELLIDO<<std::left<<std::setw(15)<<NNOMBRE <<std::left<<std::setw(15)<<TTELEFONO<<std::left<<std::setw(15)<<FFECHA<<std::left<<std::setw(15)<<DDPI<<std::left<<std::setw(15)<<DDIRECCION<<std::left<<std::setw(15)<<IIDUSER << "\n";
	file.close();
}

//Funcion para imprimir los datos de puestos
void Persona::Imprimir()
{

	system("cls");
	fstream file;
	int total=0;
	cout<<"\n..............................Tabla de Detalles de Empleado ........................"<<endl;
	file.open("PUESTO.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> ID >>AAPELLIDO >> NNOMBRE>> TTELEFONO >> DDPI >> DDIRECCION>>FFECHA>>IIDUSER;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t  ID: "<<ID<<endl;
			cout<<"\t\t\t Apellido: "<<AAPELLIDO<<endl;
			cout<<"\t\t\t Nombre: "<<NNOMBRE<<endl;
			cout<<"\t\t\t Telefono: "<<TTELEFONO<<endl;
			cout<<"\t\t\t DPI: "<<DDPI<<endl;
			cout<<"\t\t\t Direccion: "<<DDIRECCION<<endl;
			cout<<"\t\t\t fecha: "<<FFECHA<<endl;
			cout<<"\t\t\t Id de usuario: "<<IIDUSER<<endl;
			file >> ID >>AAPELLIDO >> NNOMBRE>> TTELEFONO >> DDPI >> DDIRECCION>>FFECHA>>IIDUSER;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}

//funcion para modificar puestos y departamentos
void Persona::Actualizar()
{

	system("cls");
	fstream file,file1;
	string participant_Dp;
	int found=0;
	cout<<"\n.............................Modificacion Detalles Empleado................................."<<endl;
	file.open("PUESTO.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Departamento a modificar: ";
		cin>>participant_Dp;
		file1.open("Record.txt",ios::app | ios::out);
		file >> ID >>AAPELLIDO >> NNOMBRE>> TTELEFONO >> DDPI >> DDIRECCION>>FFECHA>>IIDUSER;
		while(!file.eof())
		{
			if(participant_Dp!=ID)
			{
			 file1<<std::left<<std::setw(15)<<ID<<std::left<<std::setw(15)<<AAPELLIDO<<std::left<<std::setw(15)<<NNOMBRE <<std::left<<std::setw(15)<<TTELEFONO<<std::left<<std::setw(15)<<FFECHA<<std::left<<std::setw(15)<<DDPI<<std::left<<std::setw(15)<<DDIRECCION<<std::left<<std::setw(15)<<IIDUSER << "\n";
			}
			else
			{
    cout<<"\t\t\tIngresa el ID del empleado: ";
    cin>>ID;
	cout<<"\t\t\tIngresa el Apellido     : ";
	cin>>AAPELLIDO;
	cout<<"\t\t\tIngresa Nombre  : ";
	cin>>NNOMBRE;
	cout<<"\t\t\tIngresa No. Telefono : ";
	cin>>TTELEFONO;
	cout<<"\t\t\tIngresa DPI  : ";
	cin>>DDPI;
	cout<<"\t\t\tIngresa Direccion  : ";
	cin>>DDIRECCION;
	cout<<"\t\t\tIngresa la Fecha  : ";
	cin>>FFECHA;
	cout<<"\t\t\tIngresa la identificacion de usuario : ";
	cin>>IIDUSER;
				file1<<std::left<<std::setw(15)<<ID<<std::left<<std::setw(15)<<AAPELLIDO<<std::left<<std::setw(15)<<NNOMBRE <<std::left<<std::setw(15)<<TTELEFONO<<std::left<<std::setw(15)<<FFECHA<<std::left<<std::setw(15)<<DDPI<<std::left<<std::setw(15)<<DDIRECCION<<std::left<<std::setw(15)<<IIDUSER << "\n";
				found++;
			}
			file >> ID >>AAPELLIDO >> NNOMBRE>> TTELEFONO >> DDPI >> DDIRECCION>>FFECHA>>IIDUSER;
		}
		file1.close();
		file.close();
		remove("PUESTO.txt");
		rename("Record.txt","PUESTO.txt");
	}
}

//funcion para conultar puestos y departamentos
void Persona::Consultar()
{

	system("cls");
	fstream file;
	int found=0;
	file.open("PUESTO.txt",ios::in);
	if(!file)
	{
		cout<<"\n..................................Datos del Departamento buscado......................................"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_Dp;
		cout<<"\n..................................Datos del Departamento buscado......................................"<<endl;
		cout<<"\n Ingrese el Departamento que quiere consultar: ";
		cin>>participant_Dp;
		file >> ID >>AAPELLIDO >> NNOMBRE>> TTELEFONO >> DDPI >> DDIRECCION>>FFECHA>>IIDUSER;
		while(!file.eof())
		{
			if(participant_Dp==ID)
			cout<<"\n\n\t\t\t Id: "<<ID<<endl;
				cout<<"\n\n\t\t\t Apellido: "<<AAPELLIDO<<endl;
			cout<<"\t\t\t Nombre: "<<NNOMBRE<<endl;
			cout<<"\t\t\t Telefono: "<<TTELEFONO<<endl;
			cout<<"\t\t\t DPI: "<<DDPI<<endl;
			cout<<"\t\t\t Direccion: "<<DDIRECCION<<endl;
			cout<<"\t\t\t fecha: "<<FFECHA<<endl;
			cout<<"\t\t\t Id de usuario: "<<IIDUSER<<endl;

				found++;
			}
			file >> ID >>AAPELLIDO >> NNOMBRE>> TTELEFONO >> DDPI >> DDIRECCION>>FFECHA>>IIDUSER;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Departamento no encontrado...";
		}
		file.close();
	}

void Persona::Borrar()
{

	system("cls");
	fstream file,file1;
	string participant_Dp;
	int found=0;
	cout<<"\n.......................................Detalles Departamento a Borrar.................................."<<endl;
	file.open("PUESTO.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Departamento que quiere borrar: ";
		cin>>participant_Dp;
		file1.open("Record.txt",ios::app | ios::out);
		file >> ID >>AAPELLIDO >> NNOMBRE>> TTELEFONO >> DDPI >> DDIRECCION>>FFECHA>>IIDUSER;
		while(!file.eof())
		{
			if(participant_Dp!= ID)
			{
				file1<<std::left<<std::setw(15)<<ID<<std::left<<std::setw(15)<<AAPELLIDO<<std::left<<std::setw(15)<<NNOMBRE <<std::left<<std::setw(15)<<TTELEFONO<<std::left<<std::setw(15)<<FFECHA<<std::left<<std::setw(15)<<DDPI<<std::left<<std::setw(15)<<DDIRECCION<<std::left<<std::setw(15)<<IIDUSER << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file>> ID >>AAPELLIDO >> NNOMBRE>> TTELEFONO >> DDPI >> DDIRECCION>>FFECHA>>IIDUSER;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Departamento no encontrado...";
		}
		file1.close();
		file.close();
		remove("PUESTO.txt");
		rename("Record.txt","PUESTO.txt");
	}
}


    void Persona::consultarDep()
{

	system("cls");
	fstream file;
	int found=0;
	file.open("PUESTO.txt",ios::in);
	if(!file)
	{
		cout<<"\n..................................Datos del Departamento buscado......................................"<<endl;
		cout<<"\n\t\t\t No hay informacion...";
	}
	else
	{
		string participant_Dp;
		cout<<"\n..................................Datos del Departamento buscado......................................"<<endl;
		cout<<"\n Ingrese el Departamento que desea ver: ";
		cin>>participant_Dp;
		file>> ID >>AAPELLIDO >> NNOMBRE>> TTELEFONO >> DDPI >> DDIRECCION>>FFECHA>>IIDUSER;
		while(!file.eof())
		{
			if(participant_Dp==ID)
			{
				cout<<"\n\n\t\t\t Id: "<<ID<<endl;
				cout<<"\n\n\t\t\t Apellido: "<<AAPELLIDO<<endl;
			cout<<"\t\t\t Nombre: "<<NNOMBRE<<endl;
			cout<<"\t\t\t Telefono: "<<TTELEFONO<<endl;
			cout<<"\t\t\t DPI: "<<DDPI<<endl;
			cout<<"\t\t\t Direccion: "<<DDIRECCION<<endl;
			cout<<"\t\t\t fecha: "<<FFECHA<<endl;
			cout<<"\t\t\t Id de usuario: "<<IIDUSER<<endl;
				found++;
			}
			file>> ID >>AAPELLIDO >> NNOMBRE>> TTELEFONO >> DDPI >> DDIRECCION>>FFECHA>>IIDUSER;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Departamento no encontrado...";
		}
		file.close();
	}
}



//Mantenimiento de Departamentos y Puestos - Maria Jose Veliz 9959-21-5909
//menu principal de puestos
void Persona::menu2()
{

    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t................................"<<endl;
	cout<<"\t\t\t .  Gestion de paciente   ."<<endl;
	cout<<"\t\t\t................................"<<endl;
	cout<<"\t\t\t 1. Ingreso paciente"<<endl;
	cout<<"\t\t\t 2. Actualizar paciente"<<endl;
	cout<<"\t\t\t 3. Consultar paciente"<<endl;
	cout<<"\t\t\t 4. Imprimir paciente"<<endl;
	cout<<"\t\t\t 5. Borrar paciente"<<endl;
	cout<<"\t\t\t 6. Regresar"<<endl;

	cout<<"\t\t\t"<<endl;
	cout<<"\t\t\t Opcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"\t\t\t"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{

    		Ingresar2();
    		cout<<"\n\t\t\t Agrega otro Empleado(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		cout <<"Empleado agregados satisfactoriamente"<<endl;
		break;
	case 2:

		Actualizar2();
		cout <<"Empleadoactualizado satisfactoriamente"<<endl;
		break;
	case 3:

		Consultar2();
		cout <<"Presiona Enter para salir"<<endl;
		break;
	case 4:

		Imprimir2();
		cout <<"Impresion realizada satisfactoriamente"<<endl;
		break;
	case 5:

		Borrar2();
		cout <<"Empleado eliminado satisfactoriamente"<<endl;
		break;
	case 6:
	    cout << "Presiona Enter para confirmar"<<endl;
        break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 6);
}


//Funcion que ingresa puestos y departamentos
void Persona::Ingresar2()
{

	system("cls");
	fstream file;
	cout<<"\n.....................................................................................................................";
	cout<<"\n.....................................Agregar detalles de PACIENTE......................................................"<<endl;
	cout<<"\t\t\tIngresa el ID del paciente: ";
	cin>>ID;
	cout<<"\t\t\tIngresa el Apellido     : ";
	cin>>AAPELLIDO;
	cout<<"\t\t\tIngresa Nombre  : ";
	cin>>NNOMBRE;
	cout<<"\t\t\tIngresa No. Telefono : ";
	cin>>TTELEFONO;
	cout<<"\t\t\tIngresa DPI  : ";
	cin>>GGENERO;
	cout<<"\t\t\tIngresa Direccion  : ";
	cin>>DDIRECCION;
	cout<<"\t\t\tIngresa la Fecha  : ";
	cin>>FFECHA;
	cout<<"\t\t\tIngresa la Fecha  : ";
	cin>>ESTADOPA;
	cout<<"\t\t\tIngresa la identificacion de usuario : ";
	cin>>REFERENCIA;
	file.open("PUESTO2.dat", ios::out | ios::binary);
	file<<std::left<<std::setw(15)<<ID<<std::left<<std::setw(15)<<AAPELLIDO<<std::left<<std::setw(15)<<NNOMBRE <<std::left<<std::setw(15)<<TTELEFONO<<std::left<<std::setw(15)<<FFECHA<<std::left<<std::setw(15)<<GGENERO<<std::left<<std::setw(15)<<DDIRECCION<<std::left<<std::setw(15)<<ESTADOPA<<std::left<<std::setw(15)<<REFERENCIA << "\n";
	file.close();
    file.open("PUESTO2.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<<ID<<std::left<<std::setw(15)<<AAPELLIDO<<std::left<<std::setw(15)<<NNOMBRE <<std::left<<std::setw(15)<<TTELEFONO<<std::left<<std::setw(15)<<FFECHA<<std::left<<std::setw(15)<<GGENERO<<std::left<<std::setw(15)<<DDIRECCION<<std::left<<std::setw(15)<<ESTADOPA<<std::left<<std::setw(15)<<REFERENCIA << "\n";
	file.close();
}

//Funcion para imprimir los datos de puestos
void Persona::Imprimir2()
{

	system("cls");
	fstream file;
	int total=0;
	cout<<"\n..............................Tabla de Detalles de Empleado ........................"<<endl;
	file.open("PUESTO2.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> ID >>AAPELLIDO >> NNOMBRE>> TTELEFONO >> GGENERO >> DDIRECCION>>FFECHA>>ESTADOPA>>REFERENCIA;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t  ID: "<<ID<<endl;
			cout<<"\t\t\t Apellido: "<<AAPELLIDO<<endl;
			cout<<"\t\t\t Nombre: "<<NNOMBRE<<endl;
			cout<<"\t\t\t Telefono: "<<TTELEFONO<<endl;
			cout<<"\t\t\t DPI: "<<GGENERO<<endl;
			cout<<"\t\t\t Direccion: "<<DDIRECCION<<endl;
			cout<<"\t\t\t fecha: "<<FFECHA<<endl;
			cout<<"\t\t\t fecha: "<<ESTADOPA<<endl;
			cout<<"\t\t\t Id de usuario: "<<REFERENCIA<<endl;
			file >> ID >>AAPELLIDO >> NNOMBRE>> TTELEFONO >> GGENERO >> DDIRECCION>>FFECHA>>ESTADOPA>>REFERENCIA;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}

//funcion para modificar puestos y departamentos
void Persona::Actualizar2()
{

	system("cls");
	fstream file,file1;
	string participant_Dp;
	int found=0;
	cout<<"\n.............................Modificacion Detalles Empleado................................."<<endl;
	file.open("PUESTO2.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Departamento a modificar: ";
		cin>>participant_Dp;
		file1.open("Record2.txt",ios::app | ios::out);
		file >> ID >>AAPELLIDO >> NNOMBRE>> TTELEFONO >> GGENERO >> DDIRECCION>>FFECHA>>ESTADOPA>>REFERENCIA;
		while(!file.eof())
		{
			if(participant_Dp!=ID)
			{
			 file1<<std::left<<std::setw(15)<<ID<<std::left<<std::setw(15)<<AAPELLIDO<<std::left<<std::setw(15)<<NNOMBRE <<std::left<<std::setw(15)<<TTELEFONO<<std::left<<std::setw(15)<<FFECHA<<std::left<<std::setw(15)<<GGENERO<<std::left<<std::setw(15)<<DDIRECCION<<std::left<<std::setw(15)<<ESTADOPA<<std::left<<std::setw(15)<<REFERENCIA << "\n";
			}
			else
			{
    cout<<"\t\t\tIngresa el ID del paciente: ";
	cin>>ID;
	cout<<"\t\t\tIngresa el Apellido     : ";
	cin>>AAPELLIDO;
	cout<<"\t\t\tIngresa Nombre  : ";
	cin>>NNOMBRE;
	cout<<"\t\t\tIngresa No. Telefono : ";
	cin>>TTELEFONO;
	cout<<"\t\t\tIngresa DPI  : ";
	cin>>GGENERO;
	cout<<"\t\t\tIngresa Direccion  : ";
	cin>>DDIRECCION;
	cout<<"\t\t\tIngresa la Fecha  : ";
	cin>>FFECHA;
	cout<<"\t\t\tIngresa la Fecha  : ";
	cin>>ESTADOPA;
	cout<<"\t\t\tIngresa la identificacion de usuario : ";
	cin>>REFERENCIA;
				file1<<std::left<<std::setw(15)<<ID<<std::left<<std::setw(15)<<AAPELLIDO<<std::left<<std::setw(15)<<NNOMBRE <<std::left<<std::setw(15)<<TTELEFONO<<std::left<<std::setw(15)<<FFECHA<<std::left<<std::setw(15)<<GGENERO<<std::left<<std::setw(15)<<DDIRECCION<<std::left<<std::setw(15)<<ESTADOPA<<std::left<<std::setw(15)<<REFERENCIA << "\n";
				found++;
			}
			file >> ID >>AAPELLIDO >> NNOMBRE>> TTELEFONO >> GGENERO >> DDIRECCION>>FFECHA>>ESTADOPA>>REFERENCIA;
		}
		file1.close();
		file.close();
		remove("PUESTO.txt");
		rename("Record.txt","PUESTO.txt");
	}
}

//funcion para conultar puestos y departamentos
void Persona::Consultar2()
{

	system("cls");
	fstream file;
	int found=0;
	file.open("PUESTO.txt",ios::in);
	if(!file)
	{
		cout<<"\n..................................Datos del Departamento buscado......................................"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_Dp;
		cout<<"\n..................................Datos del Departamento buscado......................................"<<endl;
		cout<<"\n Ingrese el Departamento que quiere consultar: ";
		cin>>participant_Dp;
		file>> ID >>AAPELLIDO >> NNOMBRE>> TTELEFONO >> GGENERO >> DDIRECCION>>FFECHA>>ESTADOPA>>REFERENCIA;
		while(!file.eof())
		{
			if(participant_Dp==ID)
		cout<<"\n\n\t\t\t  ID: "<<ID<<endl;
			cout<<"\t\t\t Apellido: "<<AAPELLIDO<<endl;
			cout<<"\t\t\t Nombre: "<<NNOMBRE<<endl;
			cout<<"\t\t\t Telefono: "<<TTELEFONO<<endl;
			cout<<"\t\t\t DPI: "<<GGENERO<<endl;
			cout<<"\t\t\t Direccion: "<<DDIRECCION<<endl;
			cout<<"\t\t\t fecha: "<<FFECHA<<endl;
			cout<<"\t\t\t fecha: "<<ESTADOPA<<endl;
			cout<<"\t\t\t Id de usuario: "<<REFERENCIA<<endl;

				found++;
			}
			file >> ID >>AAPELLIDO >> NNOMBRE>> TTELEFONO >> GGENERO >> DDIRECCION>>FFECHA>>ESTADOPA>>REFERENCIA;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Departamento no encontrado...";
		}
		file.close();
	}

void Persona::Borrar2()
{

	system("cls");
	fstream file,file1;
	string participant_Dp;
	int found=0;
	cout<<"\n.......................................Detalles Departamento a Borrar.................................."<<endl;
	file.open("PUESTO2.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Departamento que quiere borrar: ";
		cin>>participant_Dp;
		file1.open("Record.txt",ios::app | ios::out);
		file >> ID >>AAPELLIDO >> NNOMBRE>> TTELEFONO >> GGENERO >> DDIRECCION>>FFECHA>>ESTADOPA>>REFERENCIA;
		while(!file.eof())
		{
			if(participant_Dp!= ID)
			{
				file1<<std::left<<std::setw(15)<<ID<<std::left<<std::setw(15)<<AAPELLIDO<<std::left<<std::setw(15)<<NNOMBRE <<std::left<<std::setw(15)<<TTELEFONO<<std::left<<std::setw(15)<<FFECHA<<std::left<<std::setw(15)<<GGENERO<<std::left<<std::setw(15)<<DDIRECCION<<std::left<<std::setw(15)<<ESTADOPA<<std::left<<std::setw(15)<<REFERENCIA << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file>> ID >>AAPELLIDO >> NNOMBRE>> TTELEFONO >> GGENERO >> DDIRECCION>>FFECHA>>ESTADOPA>>REFERENCIA;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Departamento no encontrado...";
		}
		file1.close();
		file.close();
		remove("PUESTO2.txt");
		rename("Record2.txt","PUESTO2.txt");
	}
}


    void Persona::consultarDep2()
{

	system("cls");
	fstream file;
	int found=0;
	file.open("PUESTO2.txt",ios::in);
	if(!file)
	{
		cout<<"\n..................................Datos del Departamento buscado......................................"<<endl;
		cout<<"\n\t\t\t No hay informacion...";
	}
	else
	{
		string participant_Dp;
		cout<<"\n..................................Datos del Departamento buscado......................................"<<endl;
		cout<<"\n Ingrese el Departamento que desea ver: ";
		cin>>participant_Dp;
		file>> ID >>AAPELLIDO >> NNOMBRE>> TTELEFONO >> GGENERO >> DDIRECCION>>FFECHA>>ESTADOPA>>REFERENCIA;
		while(!file.eof())
		{
			if(participant_Dp==ID)
			{
				cout<<"\n\n\t\t\t  ID: "<<ID<<endl;
			cout<<"\t\t\t Apellido: "<<AAPELLIDO<<endl;
			cout<<"\t\t\t Nombre: "<<NNOMBRE<<endl;
			cout<<"\t\t\t Telefono: "<<TTELEFONO<<endl;
			cout<<"\t\t\t DPI: "<<GGENERO<<endl;
			cout<<"\t\t\t Direccion: "<<DDIRECCION<<endl;
			cout<<"\t\t\t fecha: "<<FFECHA<<endl;
			cout<<"\t\t\t fecha: "<<ESTADOPA<<endl;
			cout<<"\t\t\t Id de usuario: "<<REFERENCIA<<endl;
				found++;
			}
			file>> ID >>AAPELLIDO >> NNOMBRE>> TTELEFONO >> GGENERO >> DDIRECCION>>FFECHA>>ESTADOPA>>REFERENCIA;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Departamento no encontrado...";
		}
		file.close();
	}
}
