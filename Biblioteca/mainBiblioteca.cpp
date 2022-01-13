#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "tiposBiblioteca.h"
#include "metodosBiblioteca.h"
using namespace std;
/* 
    Integrantes:
    Ana Milena Hernandez Garcia
    Johan Santiago Silva Hernandez Grupo:402
    Samuel Remolina Alvarez 
*/

int main() {
	Libro libros[10];
    int cantidad;
    int opcion;
    string gene;
    string idi;
    char caracter1;
	char caracter2;
    do{
    	cout<<"Bienvenido a la Biblioteca\n";
    	cout<<"Ingrese 1 para ingresar los libros.\n";
    	cout<<"Ingrese 2 para ordenar los libros por titulo.\n";
    	cout<<"Ingrese 3 para ordenar los libros por numero de paginas.\n";
    	cout<<"Ingrese 4 para buscar libros por genero.\n";
    	cout<<"Ingrese 5 para buscar libros por idioma.\n";
    	cout<<"Ingrese 6 para reemplazar un caracter de la editorial de los libros.\n";
    	cout<<"Ingrese 7 para salir.\n";
    	cout<<"Elija entre las opciones: ";
    	cin>>opcion;
    	switch(opcion){
    		case 1:
    	    cout<<"Ingrese el numero de libros: ";
    	    cin>>cantidad;
    		leerLibros(libros,cantidad);
			cout<<"\n";	
			break;
		 
			case 2:
			cout<<"Los libros ordenados por titulo son:\n\n";
	        bubbleSort(libros,cantidad);
	        escribirLibros(libros,cantidad);
	        cout<<"\n\n";
			break;
			
			case 3:
			cout<<"Los libros ordenados por numero de paginas son:\n\n";
			selectionSort(libros,cantidad);
			escribirLibros(libros,cantidad);
			cout<<"\n\n";
			break;
			
			case 4:
			cout<<"Ingrese el genero en el que desea encontrar los libros: ";
			cin>>gene;
			cout<<"Los libros encontrados por genero son:\n\n";
	        cout<<"-------------------------------------------------------------------------------------------------\n";
			busquedaGenero(libros,cantidad,gene);
            cout<<"-------------------------------------------------------------------------------------------------\n\n";
			break; 
			
			case 5:
			cout<<"Ingrese el idioma en el que desea encontrar los libros: ";
			cin>>idi;
			cout<<"Los libros encontrados por idioma son:\n\n";
			cout<<"-------------------------------------------------------------------------------------------------\n";
			busquedaIdioma(libros,cantidad,idi);
            cout<<"-------------------------------------------------------------------------------------------------\n\n";
			break;
			
			case 6:
			cout<<"Ingrese el caracter que desea reemplazar: ";
	        cin>>caracter1;
	        cout<<"Ingrese el caracter que lo reemplazara: ";
	        cin>>caracter2;
		    reemplazoCaracter(libros,cantidad,caracter1,caracter2);
		    escribirLibros(libros,cantidad);
		    cout<<"\n\n";
			break;
			default:
		    cout<<"Vuelve pronto...";
		    break;
		}
    	
	}
	while(opcion!=7);
	getch();
	return 0;
}
