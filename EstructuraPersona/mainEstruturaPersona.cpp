#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "tipos.h"
#include "metodos.h"
using namespace std;

/*
    Integrantes:
    Samuel Remolina Alvarez
    Johan Sebastian Moreno Lugo
*/

int main() {
	Persona personas[10];
	int cantidad;
	int h,m;
	cout<<"Ingrese el numero de personas: ";
    cin>>cantidad;
    
	leerPersonas(personas,cantidad);
	
	
	cout<<"Los datos ordenados por edad son:\n";
	metodoBurbuja(personas,cantidad);
	escribirPersona(personas,cantidad);
	
	cout<<"\n\nLa cantidad de hombres es: ";
    h = contadorHombres(personas,cantidad);
    cout<<h;
    cout<<"\n\nLa cantidad de mujeres es: ";
    m = contadorMujeres(personas,cantidad);
    cout<<m<<"\n\n";
    
    muestraHermanos(personas,cantidad);
    muestraPrimosoTioSobrino(personas,cantidad);
    muestraAbueloNieto(personas,cantidad);
	getch();
	return 0;
}
