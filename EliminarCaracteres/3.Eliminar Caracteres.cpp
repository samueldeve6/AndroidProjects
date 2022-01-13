#include <iostream>
using namespace std;

struct Frase{
	string palabra;
	Frase *sig;
};

void leerFrase(Frase*&);
void imprimirFrase(Frase*&);
void eliminarCaracter(Frase*&, char);

int main(){
	Frase *frase=NULL;
	leerFrase(frase);
	imprimirFrase(frase);
	do{
		char caracter;
		cout<<"\nIngrese el caracter que desea eliminar (Ingrece 0 para terminar): ";
		cin>>caracter;
		if(caracter=='0') break;
		eliminarCaracter(frase,caracter);
		imprimirFrase(frase);
	}while(true);
	return 0;
}

void leerFrase(Frase *&frase){
	Frase *ultima=NULL;
	cout<<"Ingrese la frase con un punto final(.) para terminar: ";
	string palabra="";
	while(palabra[palabra.length()-1]!='.'){
		cin>>palabra;
		if(frase==NULL){
			frase = new Frase();
			frase->palabra=palabra;
			ultima=frase;
		}else{
			ultima->sig=new Frase();
			ultima=ultima->sig;
			ultima->palabra=palabra;
		}
	}
	ultima->sig=NULL;
}

void imprimirFrase(Frase *&frase){
	Frase *q=frase;
	cout<<"\nFrase: ";
	while(q!=NULL){
		cout<<q->palabra<<" ";
		q=q->sig;
	}
}

void eliminarCaracter(Frase *&frase, char caracter){
	Frase *q=frase;
	while(q!=NULL){
		int posicion=q->palabra.find(caracter);
		while(posicion<q->palabra.length()){
			q->palabra.erase(posicion,1);
	     	posicion=q->palabra.find(caracter);
		}
		q=q->sig;
	}
}
