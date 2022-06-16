#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include<conio.h>
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ios;
using std::left;
using std::right;
using std::fixed;
using std::showpoint;

#include <fstream>

using std::ofstream;
using std::ostream;
using std::fstream;

#include <iomanip>

using std::setw;
using std::setprecision;

#include <cstdlib>
using namespace std;

class Persona
{
    public:
    Persona( int = 0, string = "", string = "", int = 0, int = 0, string = " ", int= 0, int= 0, double= 0);
    // Funciones para obtener el ID

   void establecerId( int );
   int obtenerNumeroId() const;

   // Funciones para acceder a los datos privados
   void establecerApellido( string );
   string obtenerApellido() const;

   void establecerPrimerNombre( string );
   string obtenerPrimerNombre() const;

    void establecerTelefono( int );
   int obtenerTelefono() const;

   void establecerDPI( int );
   int obtenerDPI() const;

   void establecerDireccion( string );
   string obtenerDireccion() const;

   void establecerFecha( int );
   int obtenerFecha() const;

   void estableceridUser( int );
   int obteneridUser() const;

    double obtenerBanco () const;
   void establecerBanco( double );

    void imprimirRegistro( fstream& );
    void imprimirRegistro2( fstream& );
    void actualizarRegistro( fstream& );
    void nuevoRegistro( fstream& );
    void eliminarRegistro( fstream& );
    void mostrarLinea( ostream&, const Persona & );
    void mostrarLinea2( ostream&, const Persona & );
    void mostrarLinea4( ostream&, const Persona & );
    int obtenerId( const char * const );
    void crearArchivoEmpleados();
    void consultarRegistro( fstream& );
    void consultarRegistro2( fstream& );
    void consultarRegistro3( fstream& );
    void consultarRegistro4( fstream& );
    void busquedaRegistro(fstream&);
    void busquedaRegistro2(fstream&);
    void mostrarLineaPantalla( const Persona &);
    void mostrarLineaPantalla2( const Persona &);
    void mostrarLineaPantalla3( const Persona &);
    fstream inicioArchivo();
    void menuTransferencia();

    private:
    int numeroId;
   char apellido[ 15 ];
   char primerNombre[ 10 ];
   int telefono;
   int DPI;
   char Direccion[31];
   int FechaNaci;
   int idUser;
   double estBancario = 1000000;
};

#endif // PERSONA_H
