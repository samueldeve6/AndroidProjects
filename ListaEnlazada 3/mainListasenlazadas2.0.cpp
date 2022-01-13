#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

/*
     Ana Milena Hernadez Garcia
     Johan Santiago Silva Hernandez 
     Samuel Remolina Alvarez
*/
struct Nodo {
	int dato;
	int datoDos;
	int datoTres;
	Nodo *siguiente;
	Nodo *siguienteDos;
	Nodo *siguienteTres;
};

void insertarLista(Nodo *&,int);
void insertarLista2(Nodo *&,int);
void insertarLista3(Nodo *&,int);
void mostrarLista(Nodo *);
void mostrarLista2(Nodo *);
void mostrarLista3(Nodo *);
void menu();
void recorrerListaAB(Nodo *, Nodo *);
void recorrerListaAC(Nodo *, Nodo *);
void recorrerListaBC(Nodo *, Nodo *);
void recorrerListaABC(Nodo *,Nodo *, Nodo *);


Nodo *lista = NULL;
Nodo *listaDos = NULL;
Nodo *listaTres = NULL;

int main() {	
    menu();		
	getch();
	return 0;
}

void menu(){
	int opcion,dato;
	char opcion2,opcion3,opcion4;
	system("color 0c");
	do{
	   cout<<"MENU\n";
	   cout<<"1. Insertar elementos a la lista #1\n";
	   cout<<"2. Insertar elementos a la lista #2\n";
	   cout<<"3. Insertar elementos a la lista #3\n";
	   cout<<"4. Mostrar lista #1\n";
	   cout<<"5. Mostrar lista #2\n";
	   cout<<"6. Mostrar lista #3\n";
	   cout<<"7. Mostrar datos repetidos en la lista 1 y 2\n";
	   cout<<"8. Mostrar datos repetidos en la lista 1 y 3\n";
	   cout<<"9. Mostrar datos repetidos en la lista 2 y 3\n";
	   cout<<"10. Mostrar datos repetidos en las tres listas\n";
	   cout<<"11. Salir\n";
	   cout<<"opcion: ";
	   cin>>opcion;
	   switch(opcion){
	   	
	   case 1: 
	   while(opcion2!='n'){
	   cout<<"Digite un numero: ";
       cin>>dato;
	   insertarLista(lista,dato);
	   cout<<"Quiere ingresar mas numeros(s/n)?\n";
	   cin>>opcion2;
	   }
	   system("pause");
	   break;
	   
	   case 2:
	   while(opcion3!='n'){
	   cout<<"Digite un numero: ";
       cin>>dato;
	   insertarLista2(listaDos,dato);
	   cout<<"Quiere ingresar mas numeros(s/n)?\n";
	   cin>>opcion3;
	   }
	   system("pause");
	   break;
	   
	   case 3:	
	   while(opcion4!='n'){
	   cout<<"Digite un numero: ";
       cin>>dato;
	   insertarLista3(listaTres,dato);
	   cout<<"Quiere ingresar mas numeros(s/n)?\n";
	   cin>>opcion4;
	   }
	   system("pause");
	   break;  
	   
	   case 4:
	   mostrarLista(lista);
	   cout<<"\n";
	   system("pause");
	   break;
	   
	   case 5:
	   mostrarLista2(listaDos);
	   cout<<"\n";
  	   system("pause");
	   break;
	
	   case 6:
	   mostrarLista3(listaTres);
	   cout<<"\n";
  	   system("pause");
	   break;	
	   	
	   case 7:	
	   cout<<"\n";
	   recorrerListaAB(lista,listaDos);
	   system("pause");
	   break;
	   
	   case 8:
	   cout<<"\n";
	   recorrerListaAC(lista,listaTres);
	   system("pause");
	   break;
	   
	   case 9:
	   cout<<"\n";
	   recorrerListaBC(listaDos,listaTres);
	   system("pause");
	   break;
	   
	   case 10:
	   cout<<"\n";
	   recorrerListaABC(lista,listaDos,listaTres);
	   system("pause");
	   break;
	   }
	   system("cls");
    }while(opcion != 11);
}

void insertarLista3(Nodo *&lista,int n){
	Nodo *nuevo_nodoTres = new Nodo();
    nuevo_nodoTres->datoTres = n;

    Nodo *aux111 = listaTres;
    Nodo *aux222;
 
    while((aux111 != NULL)){
    	aux222 = aux111;
    	aux111 = aux111->siguienteTres;
	}
	if(listaTres == aux111){
		listaTres = nuevo_nodoTres;
	}
	else{
		aux222->siguienteTres = nuevo_nodoTres;
	}
	nuevo_nodoTres->siguienteTres = aux111;
	
	cout<<"Elemento "<<n<<" insertado satisfactoriamente\n";
}
void mostrarLista3(Nodo *lista){
     Nodo *actualTres = new Nodo();
     actualTres = listaTres;
     
     while(actualTres != NULL){
     	cout<<actualTres->datoTres<<" -> ";
     	actualTres = actualTres->siguienteTres;
	 }
}


void insertarLista2(Nodo *&lista,int n){
	Nodo *nuevo_nodoDos = new Nodo;
    nuevo_nodoDos->datoDos = n;

    Nodo *aux11 = listaDos;
    Nodo *aux22;
 
    while((aux11 != NULL)){
    	aux22 = aux11;
    	aux11 = aux11->siguienteDos;
	}
	if(listaDos == aux11){
		listaDos = nuevo_nodoDos;
	}
	else{
		aux22->siguienteDos = nuevo_nodoDos;
	}
	nuevo_nodoDos->siguienteDos = aux11;
	
	cout<<"Elemento "<<n<<" insertado satisfactoriamente\n";
}
void mostrarLista2(Nodo *lista){
     Nodo *actualDos = new Nodo();
     actualDos = listaDos;
     
     while(actualDos != NULL){
     	cout<<actualDos->datoDos<<" -> ";
     	actualDos = actualDos->siguienteDos;
	 }
}


void insertarLista(Nodo *&lista,int n){
    struct Nodo *nuevo_nodo ;
	nuevo_nodo = new struct Nodo;
    nuevo_nodo->dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;
 
    while((aux1 != NULL)){
    	aux2 = aux1;
    	aux1 = aux1->siguiente;
	}
	if(lista == aux1){
		lista = nuevo_nodo;
	}
	else{
		aux2->siguiente = nuevo_nodo;
	}
	nuevo_nodo->siguiente = aux1;
	
	cout<<"Elemento "<<n<<" insertado satisfactoriamente\n";
}

void mostrarLista(Nodo *lista){
     Nodo *actual = new Nodo();
     actual = lista;
    
     while(actual != NULL){
     	cout<<actual->dato<<" -> ";
     	actual = actual->siguiente;
	 }
}
 
 
void recorrerListaAB(Nodo *lista, Nodo *listaDos){
	    struct Nodo *p;
	    struct Nodo *q;
        int num,aux=0,conta=0;
	    p=lista;
		while(p!=NULL){
		q=listaDos;
		    while(q!=NULL){
			if(p->dato==q->datoDos){
				num=p->dato;
				if (num == 0 && conta < 1){
					cout<<"El dato repetido es: "<<num<<endl;
			        conta++;
				}
				if(num>0 && num!=aux){
					cout<<"El dato repetido es: "<<num<<endl;
					aux=num;
				}
			}
			q=q->siguienteDos;
		}
		p=p->siguiente;	
	}  
	
	
}

void recorrerListaAC(Nodo *lista, Nodo *listaTres){
	struct Nodo *p2;
	struct Nodo *q2;
	int numero=0,temp=0,cont=0;
	p2 = lista; 
	while(p2!=NULL){
	q2=listaTres;
	    while(q2!=NULL){
	    	if(p2->dato==q2->datoTres){
	    		numero=p2->dato;
	    		if (numero == 0 && cont < 1){
					cout<<"El dato repetido es: "<<numero<<endl;
			        cont++;
				}
	    		if(numero>0 && numero!=temp){
	    			cout<<"El dato repetido es: "<<numero<<endl;
	    			temp=numero;
				}
			}
		q2=q2->siguienteTres;
		}
	p2=p2->siguiente;
	}
}

void recorrerListaBC(Nodo *listaDos, Nodo *listaTres){
	struct Nodo *p3;
	struct Nodo *q3;
	int number=0,tempo=0,contad=0;
	p3 = listaDos; 
	while(p3!=NULL){
	q3=listaTres;
	    while(q3!=NULL){
	    	if(p3->datoDos==q3->datoTres){
	    		number=p3->datoDos;
	    		if (number == 0 && contad < 1){
					cout<<"El dato repetido es: "<<number<<endl;
			        contad++;
				}
	    		if(number>0 && number!=tempo){
	    			cout<<"El dato repetido es: "<<number<<endl;
	    			tempo=number;
				}
			}
		q3=q3->siguienteTres;
		}
	p3=p3->siguienteDos;
	}
}

void recorrerListaABC(Nodo *lista, Nodo *listaDos, Nodo *listaTres){
	struct Nodo *p4;
	struct Nodo *q4;
	struct Nodo *r4;
	int nu=0,temporal=0,contador=0;
	p4 = lista;
	while(p4!=NULL){
	    q4=listaDos;
	    while(q4!=NULL){
	    	r4=listaTres;
	    	while(r4!=NULL){
	    		if(p4->dato==q4->datoDos && p4->dato==r4->datoTres){
	    		nu=p4->dato;
	    		if (nu == 0 && contador < 1){
					cout<<"El dato repetido es: "<<nu<<endl;
			        contador++;
				  }
	    		if(nu>0 && nu!=temporal){
	    			cout<<"El dato repetido es: "<<nu<<endl;
	    			temporal=nu;
				  }
			    }
	    	r4=r4->siguienteTres;	
			}
		q4=q4->siguienteDos;
		}
	p4=p4->siguiente;	
	}
}




