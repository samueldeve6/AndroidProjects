#include <iostream>
using namespace std;

struct Lista{
	int valor;
	Lista *sig;
};

void leerLista(Lista *&);
void imprimirLista(Lista *&);
Lista* conjuncion(Lista *&, Lista *&);

int main(){
	Lista *listaA=NULL;
	Lista *listaB=NULL;
	Lista *listaC=NULL;
	Lista *listaAB=NULL;
	Lista *listaAC=NULL;
	Lista *listaBC=NULL;
	Lista *listaABC=NULL;
	leerLista(listaA);
	leerLista(listaB);
	leerLista(listaC);
	listaAB=conjuncion(listaA,listaB);
	listaAC=conjuncion(listaA,listaC);
	listaBC=conjuncion(listaB,listaC);
	listaABC=conjuncion(listaAB,listaBC);
	cout<<"Lista A={";imprimirLista(listaA);cout<<"}"<<endl;
	cout<<"Lista B={";imprimirLista(listaB);cout<<"}"<<endl;
	cout<<"Lista C={";imprimirLista(listaC);cout<<"}"<<endl;
	cout<<"Lista ABC={";imprimirLista(listaABC);cout<<"}"<<endl;
	cout<<"Lista AB={";imprimirLista(listaAB);cout<<"}"<<endl;
	cout<<"Lista AC={";imprimirLista(listaAC);cout<<"}"<<endl;
	cout<<"Lista BC={";imprimirLista(listaBC);cout<<"}"<<endl;
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
	Lista *q=lista;
	while(q!=NULL){
		cout<<q->valor;
		if(q->sig!=NULL) cout<<", ";
		q=q->sig;
	}
}

Lista* conjuncion(Lista *&listaA, Lista *&listaB){
	Lista *p=listaA;
	Lista *listaAB=NULL;
	Lista *r;
	while(p!=NULL){
		Lista *q=listaB;
		while(q!=NULL){
			if(p->valor==q->valor){
				if(listaAB==NULL){
					listaAB=new Lista();
					listaAB->valor=p->valor;
					r=listaAB;
				}else{
					r->sig=new Lista();
					r=r->sig;
					r->valor=p->valor;
				}
			}
			q=q->sig;
		}
		p=p->sig;
	}
	r->sig=NULL;
	return listaAB;
}

