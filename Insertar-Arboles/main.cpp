#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
struct Nodo{
   int dato;
   Nodo *izq;
   Nodo *der;	
   Nodo *padre;
};
//Prototipos de funcion
void menu();
Nodo *crearNodo(int,Nodo *);
void insertarNodo(Nodo *&,int,Nodo *);
void mostrarArbol(Nodo *,int);
bool busqueda(Nodo *,int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);
void eliminar(Nodo *,int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *,Nodo *);
void destruirNodo(Nodo *);

Nodo *arbol = NULL;
int main() {
	menu();
	getch();
	return 0;
}
//Funcion del menu
void menu(){
	int dato,opcion,contador=0;
	do{
		cout<<"\t Menu"<<endl;
		cout<<"1. Insertar un nuevo nodo."<<endl;
		cout<<"2. Mostrar el arbol completo."<<endl;
		cout<<"3. Buscar un elemento en el arbol."<<endl;
		cout<<"4. Recorrer el arbol en pre-orden"<<endl;
		cout<<"5. Recorrer el arbol en in-orden."<<endl;
		cout<<"6. Recorrer el arbol en post-orden."<<endl;
		cout<<"7. Eliminar un nodo del arbol."<<endl;
		cout<<"8. Salir."<<endl;
		cout<<"Elija una opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1: cout<<"\nDigite un numero: ";
			        cin>>dato;
			        insertarNodo(arbol,dato,NULL);
			        cout<<"\n";
			        system("pause");
			        break;
			case 2: cout<<"\nMostrando el arbol completo:\n\n";
			        mostrarArbol(arbol,contador);
			        cout<<"\n";
			        system("pause");
			        break;
			case 3: cout<<"\nDigite el elemento a buscar: ";
		            cin>>dato;
		            if(busqueda(arbol,dato) == true){
		            	cout<<"\nElemento "<<dato<<" a sido encontrado en el arbol.\n";
					}else{
						cout<<"\nElemento no encontrado\n";
					}
					cout<<endl;
					system("pause");
					break;
			case 4: cout <<"\nRecorrido en pre-orden: ";
			        preOrden(arbol); 
			        cout<<endl<<endl;
			        system("pause");
			        break;
			        
		    case 5: cout<<"\nRecorrido en in-orden: ";
		            inOrden(arbol);
		            cout<<"\n\n";
		            system("pause");
		            break;
		    case 6: cout<<"\nRecorrido en post-orden: ";
		            postOrden(arbol);
		            cout<<"\n\n";
		            system("pause");
		    	    break;
		    case 7: cout<<"\nDigite el numero a eliminar: ";
		            cin>>dato;
		            eliminar(arbol,dato);
		            cout<<"\n";
		            system("pause");
					break;
		    
		}  
		system("cls");
	}while(opcion!=8);
}

//Funcion para crear un nuevo nodo
Nodo *crearNodo(int n, Nodo *padre){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->padre = padre;
    return nuevo_nodo;
    
}

//Funcion para insertar elementos en el arbol
void insertarNodo(Nodo *&arbol,int n, Nodo *padre){
	if(arbol == NULL){
		Nodo *nuevo_nodo = crearNodo(n,padre);
		arbol= nuevo_nodo;
	}else{  //Si el arbol tiene un nodo o mas 
		int valorRaiz = arbol->dato;
		if(n < valorRaiz){//Si el elemento es menor a la raiz, insertamoos en la izquierda
			insertarNodo(arbol->izq,n,arbol);
		}else{ //Si eñ elemento es mayor a la raiz, insertramos en la derecha
		      insertarNodo(arbol->der,n,arbol);
			}
		}
	}

//Funcion para mostrar el arbol completo
void mostrarArbol(Nodo *arbol,int cont){
	if(arbol == NULL){
		return;
	}else{
		mostrarArbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}

//Funcion para buscar un elemento en el arbol

bool busqueda(Nodo *arbol, int n){
	if(arbol==NULL){
		return false;
	}else if(arbol->dato == n){// Si el nodo es igual a elemento
		return true;
	}else if(n < arbol->dato){
		return busqueda(arbol->izq,n);
	}else{
		return busqueda(arbol->der,n);
	}
}

//Funcion para recorrer el arbol en PROFUNDIDAD en PRE-ORDEN
void preOrden(Nodo *arbol){
	if(arbol == NULL){ //Si el arbol esta vacio 
		return;
	}else{
		cout<<arbol->dato<<" - ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

//Funcion para recorrer el arbol en PROFUNDIDAD en IN-ORDEN
void inOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}else{
		inOrden(arbol->izq);
		cout<<arbol->dato<<" - ";
		inOrden(arbol->der);
	}
	
}

//Funcion para recorrer el arbol en PROFUNDIDAD en POST-ORDEN
void postOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}else{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout<<arbol->dato<<" - ";
	}
}

//Funcion para eliminar un nodo del arbol
void eliminar(Nodo *arbol,int n){
	if(arbol==NULL){
		return;// No haces nada
	}else if(n < arbol->dato){ //Si el valor es menor
		eliminar(arbol->izq,n); //Busca por la izquierda
	}else if(n > arbol->dato){ //Si el valor es mayor
		eliminar(arbol->der,n); //Busca por la derecha
	}else{ //Si ya encontraste el valor
         eliminarNodo(arbol);		
	}
}

//Funcion para determinar el nodo mas izquierdo posible
Nodo *minimo(Nodo *arbol){
	if(arbol==NULL){ //Si el arbol esta vacio
		return NULL; //retornas nulo
	}
	if(arbol->izq){ //Si tiene hijo izquierdo
		return minimo(arbol->izq);
	}
	else{ //Si no tiene hijo izquierdo
		return arbol; //Retornamos el mismo  nodo
	}
}

//Funcion para reemplazar dos nodos
void reemplazar(Nodo *arbol,Nodo *nuevoNodo){
	if(arbol->padre){
		//arbol->padre hay que asignarle su nuevo hijo
		if(arbol->dato == arbol->padre->izq->dato){
			arbol->padre->izq = nuevoNodo;
		}
		else if(arbol->dato == arbol->padre->der->dato){
			arbol->padre->der = nuevoNodo;
		}
	}
	if(nuevoNodo){
		//Procedemos a asignarle su nuevo padre
		nuevoNodo->padre = arbol->padre;
	}
}
//Funcion para destruir un nodo
void destruirNodo(Nodo *nodo){
	nodo->izq = NULL;
	nodo->der = NULL;
	delete nodo;
}

//Funcion para eliminar el nodo encontrado
void eliminarNodo(Nodo *nodoEliminar){
	 if(nodoEliminar->izq && nodoEliminar->der){ //Si el nodo tiene hijo izquierdo y hijo derecho
	 	Nodo *menor = minimo(nodoEliminar->der);
	 	nodoEliminar->dato = menor->dato;
	 	eliminarNodo(menor);
	 }
	 else if(nodoEliminar->izq){ //Si el nodo tiene hijo izquierdo
	 	reemplazar(nodoEliminar,nodoEliminar->izq);
	 	destruirNodo(nodoEliminar);
	 }
	 else if(nodoEliminar->der){
	 	reemplazar(nodoEliminar,nodoEliminar->der);
	 	destruirNodo(nodoEliminar);
	 }
	 else{ //Si el nodo no tiene hijos(Este seria un nodo hoja)
	     reemplazar(nodoEliminar,NULL);
	     destruirNodo(nodoEliminar);
	 }
}
