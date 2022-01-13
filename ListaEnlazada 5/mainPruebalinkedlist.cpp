#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

enum Insercion
{
	InsercionInicio,
	InsercionFin,
	InsercionAdelanteDe
};
struct Nodo {
	int dato;
	Nodo *Siguiente;
};

void insertarNodo(Nodo *& cab, Nodo *& fin, Nodo *& aux, Insercion tipoInsercion, int dato);

void recorrerSiguiente(Nodo *& cab, Nodo *&aux);

void recorrerTodo(Nodo *& cab);

int menuPrincipal();

int menuTipoInsercion();

int main() {
	int dato, op = 0;
	Nodo *cab, *fin, *aux;
	cab = fin = aux = NULL;
	do {
		system("CLS");
		if (aux != NULL)
			cout << "\nEl auxiliar es: " << aux->dato;
		switch (op = menuPrincipal())
		{
		case 1:
			cout << "	\nIngrese el dato a insertar: ";
			cin >> dato;
			switch (menuTipoInsercion())
			{
				case 1:
					insertarNodo(cab, fin, aux, InsercionInicio, dato);
					break;
				case 2:
					insertarNodo(cab, fin, aux, InsercionFin, dato);
					break;
				case 3:
					insertarNodo(cab, fin, aux, InsercionAdelanteDe, dato);
					break;
			}
			break;
		case 2:
			recorrerSiguiente(cab,aux);
			break;
		case 3:
			recorrerTodo(cab);
			break;
		}
		system("PAUSE");
	} while (op != 0);
}

int menuPrincipal() {
	int op = 0;
	cout << "\n	1.Insetar Nodo\n	2.Mostrar siguiente Nodo\n	3.Mostrar Lista\n	0.Salir\n	Seleccion: ";
	cin >> op;
	return op;
}

int menuTipoInsercion() {
	int op = 0;
	cout << "\n	1.Inicio\n	2.Fin\n	3.Despues de aux\n Seleccion: ";
	cin >> op;
	return op;
}

void insertarNodo(Nodo *& cab, Nodo *& fin, Nodo *& aux, Insercion tipoInsercion, int dato) {
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = dato;
	nuevo_nodo->Siguiente = NULL;

	if (cab == NULL) {
		cab = nuevo_nodo;
		fin = nuevo_nodo;
		aux = nuevo_nodo;
	}
	else {

		switch (tipoInsercion)
		{
			case InsercionInicio:
				nuevo_nodo->Siguiente = cab;
				cab = nuevo_nodo;
				break;
			case InsercionFin:
				fin->Siguiente = nuevo_nodo;
				fin = nuevo_nodo;
				
				break;
			case InsercionAdelanteDe:
				nuevo_nodo->Siguiente = aux->Siguiente;
				aux->Siguiente = nuevo_nodo;
				break;
		}
		aux = cab;
	}
}

void recorrerSiguiente(Nodo *& cab, Nodo *& aux)
{
	if (aux != NULL) {
		cout << "\nDato " << aux->dato << endl;
		aux = aux->Siguiente;
	}
}

void recorrerTodo(Nodo *& cab) {
	Nodo * aux = cab;
	while (aux != NULL) {
		cout << "\nDato " << aux->dato << endl;
		aux = aux->Siguiente;
	}
}
