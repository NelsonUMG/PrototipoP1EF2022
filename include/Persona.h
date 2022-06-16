#ifndef PERSONA_H
#define PERSONA_H
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;

class Persona
{

    public:
        string ID, NNOMBRE,AAPELLIDO,TTELEFONO,DDPI,DDIRECCION,FFECHA,IIDUSER,BBANCO,GGENERO,DIRECCIONPA,ESTADOPA,REFERENCIA;
        void menu ();
        void menu2();
            void Ingresar();
            void Ingresar2();
            void Actualizar ();
            void Actualizar2();
            void Consultar ();
            void Consultar2();
            void Imprimir ();
            void Imprimir2 ();
            void Borrar ();
            void Borrar2 ();
            void consultarDep();
            void consultarDep2();


    protected:

    private:
};



#endif // PERSONA_H
