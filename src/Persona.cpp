#include "MenuGeneral.h"
#include "Persona.h"
#include <iostream>
#include<conio.h>
using namespace std;
using std::string;
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include<string>
Persona::Persona(int valorNumeroId,
   string valorApellido, string valorPrimerNombre, int Valortelefono, int ValorDPI, string ValorDireccion, int ValorFecha, int ValoridUser, double ValorBancario)
{
   establecerId( valorNumeroId );
   establecerApellido( valorApellido );
   establecerPrimerNombre( valorPrimerNombre );
   establecerTelefono( Valortelefono );
   establecerDPI(ValorDPI);
   establecerDireccion(ValorDireccion);
   establecerFecha(ValorFecha);
   estableceridUser(ValoridUser);
   establecerBanco(ValorBancario);
}
// obtener el valor del ID
int Persona::obtenerNumeroId() const
{
   return numeroId;

}

// establecer el valor del ID
void Persona::establecerId( int valorNumeroId )
{
   numeroId = valorNumeroId;

}

// obtener el valor del apellido
string Persona::obtenerApellido() const
{
   return apellido;

}

// establecer el valor del apellido
void Persona::establecerApellido( string apellidoString )
{
   // copiar a lo más 15 caracteres de la cadena en apellido
   const char *valorApellido = apellidoString.data();
   int longitud = strlen( valorApellido );
   longitud = ( longitud < 15 ? longitud : 14 );
   strncpy( apellido, valorApellido, longitud );

   // anexar caracter nulo al apellido
   apellido[ longitud ] = '\0';

}

// obtener el valor del primer nombre
string Persona::obtenerPrimerNombre() const
{
   return primerNombre;

}

// establecer el valor del primer nombre
void Persona::establecerPrimerNombre( string primerNombreString )
{

   const char *valorPrimerNombre = primerNombreString.data();
   int longitud = strlen( valorPrimerNombre );
   longitud = ( longitud < 10 ? longitud : 9 );
   strncpy( primerNombre, valorPrimerNombre, longitud );


   primerNombre[ longitud ] = '\0';

}
int Persona::obtenerTelefono() const
{
   return telefono;

}

void Persona::establecerTelefono( int Valortelefono )
{
   telefono = Valortelefono;
}
int Persona::obtenerDPI() const
{
   return DPI;

}

void Persona::establecerDPI( int ValorDPI )
{
   DPI = ValorDPI;
}
string Persona::obtenerDireccion() const
{
   return Direccion;

}


void Persona::establecerDireccion( string ValorDireccionS )
{

   const char *ValorDireccion = ValorDireccionS.data();
   int longitud = strlen( ValorDireccion );
   longitud = ( longitud < 32 ? longitud : 31 );
   strncpy( Direccion, ValorDireccion, longitud );


   Direccion[ longitud ] = '\0';

}
int Persona::obtenerFecha() const
{
   return FechaNaci;

}

void Persona::establecerFecha( int ValorFecha )
{
   FechaNaci = ValorFecha;
}
int Persona::obteneridUser() const
{
   return idUser;

}

void Persona::estableceridUser( int ValorideUser )
{
   idUser = ValorideUser;
}
double Persona::obtenerBanco() const
{
   return estBancario;
}

void Persona::establecerBanco(double ValorBancario){

    estBancario = ValorBancario;
}
void Persona::imprimirRegistro( fstream &leerDeArchivo )
{
   // crear archivo de texto
   ofstream archivoImprimirSalida( "EMPLEADOS.txt", ios::out );

   // salir del programa si ofstream no puede crear el archivo
   if ( !archivoImprimirSalida ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   }

   archivoImprimirSalida<< left << setw( 4 ) << "ID" << setw( 12 )
       << "Apellido" << setw( 14 ) << "Primer nombre" <<
       setw( 12 )<<"Telefono"<<setw(16)<<"DPI"<<setw(27)<<"Direccion"
       <<setw( 12 )<< "Fecha de Nacimiento"<<setw(12)<<"Id Usuario"<< endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   Persona empleado;
   leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( empleado.obtenerNumeroId() != 0 )
         mostrarLinea( archivoImprimirSalida, empleado );

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
         sizeof( Persona ) );

   }
}
void Persona::imprimirRegistro2( fstream &leerDeArchivo )
{
   // crear archivo de texto
   ofstream archivoImprimirSalida( "Paciente.txt", ios::out );

   // salir del programa si ofstream no puede crear el archivo
   if ( !archivoImprimirSalida ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   }
   archivoImprimirSalida<< left << setw( 4 ) << "ID" << setw( 12 )
       << "Apellido" << setw( 14 ) << "Primer nombre"<< setw( 14 ) << "Genero"<<setw(27)<<"Direccion"<<
       setw( 12 )<<"Telefono"<<setw( 12 )<< "Estado Paciente"<<setw(12)<<"Id Referencia"<< endl;
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   Persona empleado;
   leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( empleado.obtenerNumeroId() != 0 )
         mostrarLinea2( archivoImprimirSalida, empleado );

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
         sizeof( Persona ) );

   }


}
void Persona::actualizarRegistro( fstream &actualizarArchivo )
{
   // obtener el número de ID a actualizar
   int numeroId = obtenerId( "Escriba el ID del empleado a modificar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivo.seekg(
      ( numeroId - 1 ) * sizeof( Persona ) );

   // leer el primer registro del archivo
   Persona empleado;
   actualizarArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );
    int choice;
   // actualizar el registro
   if ( empleado.obtenerNumeroId() != 0 ) {

cout << left << setw( 4 ) << "ID" << setw( 12 )
       << "Apellido" << setw( 14 ) << "Primer nombre" <<
       setw( 12 )<<"Telefono"<<setw(16)<<"DPI"<<setw(27)<<"Direccion"
       <<setw( 12 )<< "Fecha de Nacimiento"<<setw(12)<<"Id Usuario"<< endl;
      mostrarLinea( cout, empleado );

      // solicitar al usuario que especifique la transacción
      cout<<""<<endl;
      cout <<"¿Que desea modificar?"<<endl;
	  cout<<"1. Telefono"<<endl;
	  cout<<"2. DPI"<<endl;
	  cout<<"3. Direccion"<<endl;
	  cout<<"4. Fecha"<<endl;
	  cout<<"5. Indentificacion Usuario"<<endl;
	  cout<<"6. Cancelar"<<endl;
	  cin >> choice;
    switch(choice)
    {
        case 1:
            //cambio de departamento
            {cout << "Ingrese el nuevo numero de telefono: "<<endl;
            int cambioCuenta;
            cin >> cambioCuenta;
            empleado.establecerTelefono( cambioCuenta );}
            break;
        case 2:
            //cambio de direccion
            {cout << "Ingrese la nueva DPI"<<endl;
            int cambioHoras;
            cin >> cambioHoras;
            empleado.establecerDPI( cambioHoras );}
            break;
        case 3:
            //cambio de telefono
            {cout << "Ingrese la nueva dirección: "<<endl;
            string cambioPuesto;
            cin >> setw( 15 )>> cambioPuesto;
            empleado.establecerDireccion( cambioPuesto );}
            break;
        case 4:
            {cout << "Ingrese la nueva fecha: "<<endl;
            int cambioEmail;
            cin >> cambioEmail;
            empleado.establecerFecha(cambioEmail );}
            break;
        case 5:
            {cout << "Ingrese el nuevo Id usuario: "<<endl;
            int cambioSueldo;
            cin >> cambioSueldo;
            empleado.estableceridUser( cambioSueldo );}
            break;
        case 6:
            cout << "Modificacion cancelada, empleado sin cambios: "<<endl;
            break;
        default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}

cout << left << setw( 4 ) << "ID" << setw( 12 )
       << "Apellido" << setw( 14 ) << "Primer nombre" <<
       setw( 12 )<<"Telefono"<<setw(16)<<"DPI"<<setw(27)<<"Direccion"
       <<setw( 12 )<< "Fecha de Nacimiento"<<setw(12)<<"Id Usuario"<< endl;
      mostrarLinea( cout, empleado );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivo.seekp(
         ( numeroId - 1 ) * sizeof( Persona ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      actualizarArchivo.write(
         reinterpret_cast< const char * >( &empleado ),
         sizeof( Persona ) );

   }

   // mostrar error si el ID no existe
   else
      cerr << "El ID #" << numeroId
         << " aun no existe" << endl;

}
void Persona::nuevoRegistro( fstream &insertarEnArchivo )
{
   // obtener el número de ID a crear
   int numeroId = obtenerId( "Ingrese el ID del nuevo empleado: " );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   insertarEnArchivo.seekg(
      ( numeroId - 1 ) * sizeof( Persona ) );

   // leer el registro del archivo
   Persona empleado;
   insertarEnArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );

   // crear el registro, si éste no existe ya
   if ( empleado.obtenerNumeroId() == 0 ) {

   char apellido[ 15 ];
   char primerNombre[ 10 ];
   int telefono;
   int DPI;
   char Direccion[31];
   int FechaNaci;
   int idUser;

      // el usuario introduce los datos
      cout << "Escriba el apellido : " << endl;
      cin >> setw( 12 ) >> apellido;
      cout << "Escriba el nombre: " << endl;
      cin >> setw( 14 ) >> primerNombre;
      cout << "Escriba el telefono: "<<endl;
      cin >> setw( 12 ) >> telefono;
      cout << "Escriba el DPI: "<<endl;
      cin >> setw(16)>> DPI ;
      cout << "Escriba la Direccion: "<<endl;
      cin >> setw(27)>> Direccion;
      cout << "Escriba la Fecha de Nacimiento: " << endl;
      cin >> setw( 12 ) >> FechaNaci;
      cout << "Escriba la identificacion de usuario "<<endl;
      cin >> setw(16)>> idUser;


      // usar valores para llenar los valores del empleado
      empleado.establecerApellido( apellido );
      empleado.establecerPrimerNombre( primerNombre );
      empleado.establecerTelefono(telefono);
      empleado.establecerDPI(DPI);
      empleado.establecerDireccion(Direccion);
      empleado.establecerFecha(FechaNaci);
      empleado.estableceridUser(idUser);
      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      insertarEnArchivo.seekp( ( numeroId - 1 ) *
         sizeof( Persona ) );

      // insertar el registro en el archivo
      insertarEnArchivo.write(
         reinterpret_cast< const char * >( &empleado ),
         sizeof( Persona ) );

   }
   else
      cerr << "El ID numero #" << numeroId
           << " ya está registrado." << endl;

}

// eliminar un registro existente
void Persona::eliminarRegistro( fstream &eliminarDeArchivo )
{
   // obtener número de ID a eliminar
   int numeroId = obtenerId( "Escriba el ID del empleado a eliminar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   eliminarDeArchivo.seekg(
      ( numeroId - 1 ) * sizeof( Persona ) );

   // leer el registro del archivo
   Persona empleado;
   eliminarDeArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );

   // eliminar el registro, si es que existe en el archivo
   if ( empleado.obtenerNumeroId() != 0 ) {
      Persona empleadoEnBlanco;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      eliminarDeArchivo.seekp( ( numeroId - 1 ) *
         sizeof( Persona ) );

      // reemplazar el registro existente con un registro en blanco
      eliminarDeArchivo.write(
         reinterpret_cast< const char * >( &empleadoEnBlanco ),
         sizeof( Persona ) );

      cout << "Empleado con ID #" << numeroId << " eliminado.\n";

   }

   else
      cerr << "No existe ningun empleado con el ID #" << numeroId<<endl;

}
//Consulta de los empleados
void Persona::consultarRegistro( fstream &leerDeArchivo )
{

    cout << left << setw( 4 ) << "ID" << setw( 12 )
       << "Apellido" << setw( 14 ) << "Primer nombre" <<
       setw( 12 )<<"Telefono"<<setw(16)<<"DPI"<<setw(27)<<"Direccion"
       <<setw( 12 )<< "Fecha de Nacimiento"<<setw(16)<<"Id Usuario"<< endl;
   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   Persona empleado;
   leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( empleado.obtenerNumeroId() != 0 )
         mostrarLineaPantalla(empleado);

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
         sizeof( Persona ) );

   }

}

void Persona::consultarRegistro2( fstream &leerDeArchivo )
{

cout << left << setw( 4 ) << "ID" << setw( 12 )
       << "Apellido" << setw( 14 ) << "Primer nombre"<< setw( 14 ) << "Genero"<<setw(27)<<"Direccion"<<
       setw( 12 )<<"Telefono"<<setw( 12 )<< "Estado Paciente"<<setw(12)<<"Id Referencia"<< endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   Persona empleado;
   leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( empleado.obtenerNumeroId() != 0 )
         mostrarLineaPantalla2(empleado);

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
         sizeof( Persona ) );

   }

}
void Persona::consultarRegistro3( fstream &leerDeArchivo )
{

cout << left << setw( 4 ) << "ID" << setw( 12 )
       << "Apellido" << setw( 14 ) << "Primer nombre" <<
       setw( 12 )<<"Telefono"<<setw(16)<<"DPI"<<setw(27)<<"Direccion"
       <<setw( 12 )<< "Fecha de Nacimiento"<<setw(16)<<"Id Usuario"<< endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   Persona empleado;
   leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( empleado.obtenerNumeroId() != 0 )
         mostrarLineaPantalla3(empleado);

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &empleado ),
         sizeof( Persona ) );

   }

}



// mostrar registro individual
void Persona::mostrarLinea( ostream &salida, const Persona &registro )
{
    salida<< left << setw( 4 ) << registro.obtenerNumeroId()
          << setw( 12 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerPrimerNombre().data()
          << setw( 12 ) << registro.obtenerTelefono()
          << setw( 16 ) << registro.obtenerDPI()
          << setw( 27 ) << registro.obtenerDireccion().data()
          << setw( 12 ) << registro.obtenerFecha()
          << setw( 16 ) << registro.obteneridUser()<<endl;

}
void Persona::mostrarLineaPantalla( const Persona &registro )
{
   cout << left << setw( 4 ) << registro.obtenerNumeroId()
          << setw( 12 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerPrimerNombre().data()
          << setw( 12 ) << registro.obtenerTelefono()
          << setw( 16 ) << registro.obtenerDPI()
          << setw( 27 ) << registro.obtenerDireccion().data()
          << setw( 12 ) << registro.obtenerFecha()
          << setw( 16 ) << registro.obteneridUser()<<endl;
}

void Persona::mostrarLinea2( ostream &salida, const Persona &registro )
{
   salida << left << setw( 4 ) << registro.obtenerNumeroId()
          << setw( 12 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerPrimerNombre().data()
          << setw( 12 ) << registro.obtenerTelefono()
          << setw( 16 ) << registro.obtenerDPI()
          << setw( 27 ) << registro.obtenerDireccion().data()
          << setw( 12 ) << registro.obtenerFecha()
          << setw( 16 ) << registro.obteneridUser()<<endl;
}
void Persona::mostrarLineaPantalla2( const Persona &registro )
{
   cout << left << setw( 4 ) << registro.obtenerNumeroId()
          << setw( 12 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerPrimerNombre().data()
          << setw( 12 ) << registro.obtenerTelefono()
          << setw( 16 ) << registro.obtenerDPI()
          << setw( 27 ) << registro.obtenerDireccion().data()
          << setw( 12 ) << registro.obtenerFecha()
          << setw( 16 ) << registro.obteneridUser()<<endl;
}

void Persona::mostrarLineaPantalla3( const Persona &registro )
{
   cout << left << setw( 4 ) << registro.obtenerNumeroId()
          << setw( 12 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerPrimerNombre().data()
          << setw( 12 ) << registro.obtenerTelefono()
          << setw( 16 ) << registro.obtenerDPI()
          << setw( 27 ) << registro.obtenerDireccion().data()
          << setw( 12 ) << registro.obtenerFecha()
          << setw( 16 ) << registro.obteneridUser()<<endl;

}
void Persona::mostrarLinea4( ostream &salida, const Persona &registro )

{   cout<<"\t\t\t................................"<<endl;
	cout<<"\t\t\t .  GEneracion de factura   ."<<endl;
	cout<<"\t\t\t................................"<<endl;
    cout<<"\t\t\t Identificacion: " <<registro.obtenerNumeroId()<<endl;
     cout<<"\t\t\t Apellido: "<<registro.obtenerApellido().data()<< endl;
     cout<<"\t\t\t Nombre: "<< registro.obtenerPrimerNombre().data()<<endl;
}
// obtener el valor del número ID del usuario
int Persona::obtenerId( const char * const indicador )
{
   int numeroId;

   do {
      cout << indicador << " (1 - 1000): ";
      cin >> numeroId;

   } while ( numeroId < 1 || numeroId > 1000 );

   return numeroId;

}
void Persona::crearArchivoEmpleados()
{
    ofstream empleadosSalida( "empleados.dat", ios::out | ios::binary );
   // salir del programa si ofstream no pudo abrir el archivo
   if ( !empleadosSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );

   }

   // crear espacios sin informacion
   Persona empleadoEnBlanco;

   for ( int i = 0; i < 1000; i++ )
      empleadosSalida.write(
         reinterpret_cast< const char * >( &empleadoEnBlanco ),
         sizeof( Persona ) );
}

fstream Persona::inicioArchivo(){
    Persona empleado;
        fstream empleadosEntradaSalida( "empleados.dat", ios::in | ios::out | ios::binary);

   // salir del programa si fstream no puede abrir el archivo
    if ( !empleadosEntradaSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      empleado.crearArchivoEmpleados();
      cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
      exit ( 1 );

    }
    return empleadosEntradaSalida;
}


//Funcion para encontrar empleado especifico
void Persona::busquedaRegistro(fstream &actualizarArchivo)
{
//Se obtiene el ID a buscar
       int numeroId = obtenerId( "Escriba el ID del empleado a buscar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivo.seekg(
      ( numeroId - 1 ) * sizeof( Persona ) );

   // leer el primer registro del archivo
   Persona empleado;
   actualizarArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );
if ( empleado.obtenerNumeroId() != 0 ) {
      //MOstrar la informacion obtenida
       cout << left << setw( 4 ) << "ID" << setw( 12 )
       << "Apellido" << setw( 14 ) << "Primer nombre" <<
       setw( 12 )<<"Telefono"<<setw(16)<<"DPI"<<setw(27)<<"Direccion"
       <<setw( 12 )<< "Fecha de Nacimiento"<<setw(12)<<"Id Usuario"<< endl;
      mostrarLinea( cout, empleado );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivo.seekp(
         ( numeroId - 1 ) * sizeof( Persona ) );

   }

   // mostrar error si el ID no existe
   else
      cerr << "El ID #" << numeroId
         << " aun no existe" << endl;

}
void Persona::busquedaRegistro2(fstream &actualizarArchivo)
{
//Se obtiene el ID a buscar
       int numeroId = obtenerId( "Escriba el ID del empleado a buscar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivo.seekg(
      ( numeroId - 1 ) * sizeof( Persona ) );

   // leer el primer registro del archivo
   Persona empleado;
   actualizarArchivo.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Persona ) );
if ( empleado.obtenerNumeroId() != 0 ) {
     mostrarLinea4( cout, empleado );
      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivo.seekp(
         ( numeroId - 1 ) * sizeof( Persona ) );

   }

   // mostrar error si el ID no existe
   else
      cerr << "El ID #" << numeroId
         << " aun no existe" << endl;

}
