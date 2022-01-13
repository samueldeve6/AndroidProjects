#include <iostream>
using namespace std;


void leerPersona(Persona &p){
	cout<<"Ingrese el genero(Hombre-Mujer): ";
	fflush(stdin);
    getline(cin,p.genero);
    
	cout<<"Ingrese el nombre: ";
	getline(cin,p.nombre);
	
	cout<<"Ingrese el primer apellido: ";
	getline(cin,p.apellidoUno);
	
	cout<<"Ingrese el segundo apellido: ";
	getline(cin,p.apellidoDos);
	
	cout<<"Ingrese la edad: ";
	cin>>p.edad;
}

void escribirPersona(Persona &p){
	cout<<"Genero: "<<p.genero<<" Nombre: "<<p.nombre<<" Primer apellido: "<<p.apellidoUno<<" Segundo apellido: "<<p.apellidoDos<<" Edad: "<<p.edad<<"\n";
}

void leerPersonas(Persona p[],int c){
	for(int i=0;i<c;i++){
		cout<<"Ingrese los datos de la persona "<<i+1<<endl;
		leerPersona(p[i]);
	}
	
}

void escribirPersona(Persona p[],int c){
	
	for(int i=0;i<c;i++){
		cout<<"----------------------------------------------------------------------------------\n"; 
		escribirPersona(p[i]);
	}
}

void metodoBurbuja(Persona p[], int cantidad){
	Persona temp;
	for(int i = 0;i<cantidad;i++){
		for(int j=0;j<cantidad-1;j++){
			if(p[j].edad>p[j+1].edad){
				temp = p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
}


int contadorHombres(Persona p[],int c){
	int i=0;
	int contadorHombre=0;
    while(i<c){
	if(p[i].genero=="Hombre"){
		contadorHombre++;
	}
	i++;
}
	return contadorHombre;
}

int contadorMujeres(Persona p[],int c){
	int i=0;
	int contadorMujer=0;
    while(i<c){
	if(p[i].genero=="Mujer"){
		contadorMujer++;
	}
	i++;
}
	return contadorMujer;
}

bool bandera=false;
void muestraHermanos(Persona p[],int c){
	string guardaNombre1;
	string guardaNombre2;
	for(int i=0; i<c; i++){
		for(int j=0; j<c-1; j++){
		    if(p[j].apellidoUno == p[j+1].apellidoUno && p[j].apellidoDos == p[j+1].apellidoDos){
		    	guardaNombre1=p[j].nombre;
		    	guardaNombre2=p[j+1].nombre;
		    	bandera=true;
					
			}
		}
	}	
	if(bandera){
	cout<<guardaNombre1<<" y "<<guardaNombre2<<" son hermanos\n";   
	}
}

void muestraPrimosoTioSobrino(Persona p[],int c){
	string guardaNombre1;
	string guardaNombre2;
	bool band=false;
	if (bandera==false){

	for(int i=0; i<c; i++){
		for(int j=0; j<c-1; j++){
		    if(p[j].apellidoUno == p[j+1].apellidoUno || p[j].apellidoDos == p[j+1].apellidoDos){
		    	guardaNombre1=p[j].nombre;
		    	guardaNombre2=p[j+1].nombre;
		    	band=true;
			}
		}
	}
	if(band){

	cout<<guardaNombre1<<" y "<<guardaNombre2<<" posiblemente son primos o tio y sobrino \n";
    }
    }
}


void muestraAbueloNieto(Persona p[],int c){
	string guardaNombre1;
	string guardaNombre2;
	bool bande=false;
	for(int i=0; i<c; i++){
		for(int j=0; j<c-1; j++){
		    if(p[j].apellidoUno == p[j+1].apellidoUno && p[j].apellidoDos != p[j+1].apellidoDos ){
		    	guardaNombre1=p[j].nombre;
		    	guardaNombre2=p[j+1].nombre;
		    	bande=true;
			}
		}
	}
	if(bande){
	cout<<guardaNombre1<<" y "<<guardaNombre2<<" posiblemente tienen un parentesco de abuelo y nieto \n";
    }
    
}
