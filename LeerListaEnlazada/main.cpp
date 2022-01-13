#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct nodo{
    int num;
    nodo *next;
};

void leerLista(nodo *&);
void imprimirLista(nodo *&);
int main (){
	nodo *lista=NULL;
	leerLista(lista);
	imprimirLista(lista);
    return 0;
}
void leerLista(nodo *&lista){
	nodo *tail=NULL;
	int number;
    cout<<"ingrese informacion(0 para salir)"<<endl;
    
    do{
    cout<<"->";
	cin>>number;
    if(number==0)break;
    if(tail!=NULL){
		tail->next=new nodo();
        tail=tail->next;
        tail->num=number;       
	}
    if(lista==NULL){
    	lista=new nodo();
		lista->num=number;
		tail=lista;
	}
	}while(true);
tail->next=NULL;
}

void imprimirLista(nodo *&lista){
	nodo *q=lista;
	while(q!=NULL){
		cout<<"->"<<q->num;
		q=q->next;
	}
	cout<<endl;
}
