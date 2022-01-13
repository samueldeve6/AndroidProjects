#include <iostream>
#include <conio.h>
using namespace std;
struct Nodo{
   char dato;
   Nodo *siguiente;	
};
//Prototipos de funciones
void menu();
void insertarCola(Nodo *&, Nodo *&, char);
bool colaVacia(Nodo *);
void suprimirCola(Nodo *&, Nodo *&, char &);
int main() {
	menu();
	getch();
	return 0;
}
void menu(){
	int op;
	char dato;
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	
	do{
		cout<<"\t---Menu----\n";
		cout<<"1. Insertar un caracter a una cola"<<endl;
		cout<<"2. Mostrar todos los elementos de la cola"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"Opcion: ";
		cin>>op;
		switch(op){
			case 1:
			cout<<"\nIngrese el caracter para agregar a la cola: ";cin>>dato;
			insertarCola(frente,fin,dato);break;
			case 2: cout<<"\nMostrando los datos de la cola: ";
			while(frente!=NULL){
				suprimirCola(frente,fin,dato);
				if(frente!=NULL){
					cout<<"->"<<dato;
				}else{
					cout<<dato<<".";
				}
			}
			system("pause");
			break;
			case 3:break;
		}
		system("cls");
	}while(op!=3);
}
//Funcion para insertar elemento a la pila
void insertarCola(Nodo *&frente,Nodo *&fin,char n){
	Nodo *nuevo = new Nodo();
	nuevo->dato=n;
	nuevo->siguiente=NULL;
	if(colaVacia(frente)){
		frente = nuevo;
	}else{
		fin->siguiente=nuevo;
	}
	fin=nuevo;
}
//Funcion para determinar si la cola esta vacia
bool colaVacia(Nodo *frente){
	return (frente==NULL)? true : false;
}
//Funcion para quitar elementos de la cola
void suprimirCola(Nodo *&frente,Nodo *&fin,char &n){
	n=frente->dato;
	Nodo *aux=frente;
	if(frente==fin){
		frente=NULL;
		fin=NULL;
	}else{
		frente=frente->siguiente;
	}
	delete aux;
}
