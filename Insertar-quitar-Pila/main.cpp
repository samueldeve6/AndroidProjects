#include <iostream>
#include<conio.h>
using namespace std;
struct Nodo{
    int dato;
    Nodo *next;
};
void agregarPila(Nodo *&,char);
void sacarPila(Nodo *&,char &);
int main() {
	Nodo *pila = NULL;
	char dato;
	char rpt;
	
	do{
		cout<<"Digite un numero: ";
		cin>>dato;
		agregarPila(pila,dato);
		cout<<"\nDesea agregar otro elemento a la pila(s/n): ";
		cin>>rpt;
	}while((rpt=='S')||(rpt=='s'));
	
	cout<<"\nSacando todos los elementos de pila: ";
	while(pila!=NULL){
		sacarPila(pila,dato);
		if(pila!=NULL){
			cout<<dato<<"->";
		}else{
			cout<<dato<<".";
		}
	}
	
	getch();
	return 0;
}

void agregarPila(Nodo *&pila, char n){
	Nodo *nuevo = new Nodo();
	nuevo->dato=n;
	nuevo->next=pila;
	pila=nuevo;
}

void sacarPila(Nodo *&pila,char &n){
	Nodo *aux = pila;
	n = aux->dato;
	pila=aux->next;
	delete aux;
}
