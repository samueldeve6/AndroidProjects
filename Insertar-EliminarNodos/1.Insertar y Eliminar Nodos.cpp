#include <iostream>
using namespace std;
struct Lista{
	int valor;
	Lista *sig;
};

void leerLista(Lista*&,int&);
void imprimirLista(Lista*&);

int main(){
	Lista *lista=NULL;
	Lista *nodo=NULL;
	int n=0,posicion=0;
	leerLista(lista, n);
	imprimirLista(lista);
	do{
		cout<<"Ingrese 0 para terminar.\n";
		cout<<"Ingrese la posicion en donde desea insertar el nodo con un numero positivo.\n";
		cout<<"Ingrese la posicion en donde desea eliminar el nodo con un numero negativo.\n";
		cout<<"siendo 1 la primera posicion y "<<n+1<<" la ultima posicion: ";
		cin>>posicion;
		if(posicion==0) break;
		if(posicion>0){
			nodo=new Lista();
			cout<<"Ingrese el valor del nodo: ";
			cin>>nodo->valor;
		}
		//Insertar
		if(posicion==1){
			nodo->sig=lista;
			lista=nodo;
			n++;
		}
		if(posicion>1 && posicion<=n){
			Lista *q=lista;
			int i=1;
			while(i<posicion-1){
				q=q->sig;
				i++;
			}
			nodo->sig=q->sig;
			q->sig=nodo;
			n++;
		}
		if(posicion==n+1){
			Lista *q=lista;
			while(q->sig!=NULL){
				q=q->sig;
			}
			q->sig=nodo;
			nodo->sig=NULL;
			n++;
		}
		//eliminar
		if(posicion==-1){
			Lista *q=lista;
			lista=lista->sig;
			delete(q);
			n--;
		}
		if(posicion<-1 && posicion>=n*-1){
			Lista *q=lista;
			int i=2;
			while(i<posicion*-1){
				q=q->sig;
				i++;
			}
			Lista *p=q->sig;
			q->sig=p->sig;
			delete(p);
		}
		if(posicion==(n)*-1){
			Lista *q=lista;
			while(q->sig->sig!=NULL){
				q=q->sig;
			}
			delete(q->sig);
			q->sig=NULL;
			n--;
		}else if(posicion==(n+1)*-1){
			cout<<"la ultima posicion posible para eliminar es: "<<n<<"\n";
		}
		imprimirLista(lista);
	}while(true);
	return 0;
}

void leerLista(Lista *&lista, int &n){
	Lista *ultimo;
	int numero;
	cout<<"Ingrese 0 para Terminar."<<endl;
	do{
		cout<<"->";
		cin>>numero;
		if(numero==0) break;
		if(lista==NULL){
			lista=new Lista();
			lista->valor=numero;
			ultimo=lista;
		}else{
			ultimo->sig=new Lista();
			ultimo=ultimo->sig;
			ultimo->valor=numero;
		}
		n++;
	}while(true);
	ultimo->sig=NULL;
}

void imprimirLista(Lista *&lista){
	Lista *q=lista;
	while(q!=NULL){
		cout<<q->valor<<" - ";
		q=q->sig;
	}
	cout<<endl;
}
