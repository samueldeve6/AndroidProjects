#include <iostream>
using namespace std;
struct Lista{
	int valor;
	Lista *sig;
};
void leerLista(Lista*&);
void imprimirLista(Lista *&);
int main() {
	Lista *lista=NULL;
	leerLista(lista);
	imprimirLista(lista);
	return 0;
}
void leerLista(Lista *&lista){
	int valor;
	Lista *q=NULL;
	cout<<"Ingrese 0 para terminar."<<endl;
	do{
		cout<<"->";
		cin>>valor;
		if(valor==0) break;
		if(q!=NULL){
			q->sig=new Lista();
			q=q->sig;
			q->valor=valor;
		}
		if(lista==NULL){
			lista=new Lista();
			lista->valor=valor;
			q=lista;
		}	
	}while(true);
	q->sig=NULL;
}

void imprimirLista(Lista *&lista){
	for(Lista *q=lista;q!=NULL;q=q->sig){
		cout<<q->valor<<" - ";
	}
	cout<<endl;
}
