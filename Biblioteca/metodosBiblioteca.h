#include <iostream>
using namespace std;

void leerLibro(Libro &l){
	cout<<"Ingrese el titulo del libro: ";
	fflush(stdin);
    getline(cin,l.titulo);
    
	cout<<"Ingrese el numero de paginas: ";
	cin>>l.numPaginas;
	
	cout<<"Ingrese el genero del libro: ";
	fflush(stdin);
	getline(cin,l.genero);
	
	cout<<"Ingrese el idioma del libro: ";
	
	getline(cin,l.idioma);
	fflush(stdin);
	cout<<"Ingrese la editorial del libro: ";
	getline(cin, l.editorial);
	fflush(stdin);
	cout<<"Ingrese el dia de lanzamiento: ";
	cin>>l.fechaLanzamiento.dia;
	fflush(stdin);
	cout<<"Ingrese el mes de lazamiento: ";
	cin>>l.fechaLanzamiento.mes;
	fflush(stdin);
	cout<<"Ingrese la anualidad de lanzamiento: ";
	cin>>l.fechaLanzamiento.anio;
	
}
void leerLibros(Libro l[],int c){
	for(int i=0;i<c;i++){
		cout<<"----------------------------------------------------------------\n";
		cout<<"Ingrese los datos del libro "<<i+1<<endl;
		
		leerLibro(l[i]);
	}
	
}
void escribirLibro(Libro &l){
	cout<<"Titulo: "<<l.titulo<<" Numero de paginas: "<<l.numPaginas<<" Genero: "<<l.genero<<" Idioma: "<<l.idioma<<" Editorial: "<<l.editorial;
    cout<<" Fecha de lanzamiento: "<<l.fechaLanzamiento.dia<<"/"<<l.fechaLanzamiento.mes<<"/"<<l.fechaLanzamiento.anio<<"\n";
}
void escribirLibros(Libro l[],int c){
	
	for(int i=0;i<c;i++){
		cout<<"----------------------------------------------------------------------------------\n"; 
		escribirLibro(l[i]);
	}
}

void bubbleSort(Libro l[], int cantidad){
	Libro temp;
	for(int i = 0;i<cantidad;i++){
		for(int j=0;j<cantidad-1;j++){
			if(l[j].titulo>l[j+1].titulo){
				temp = l[j];
				l[j]=l[j+1];
				l[j+1]=temp;
			}
		}
	}
}
int minimo=0;
void selectionSort(Libro l[], int cantidad){
	Libro temporal;
	for (int i=0; i<=cantidad-1;i++){
		minimo = i;
        for(int j=i+1;j<cantidad;j++) {
            if(l[j].numPaginas<l[minimo].numPaginas){
            	minimo = j;
			}
        }
        temporal = l[i];
        l[i] = l[minimo];
        l[minimo] = temporal;
    }
}
void busquedaGenero(Libro l[], int cantidad, string gen){
int i;
bool found = false;
i=0;
Libro aux;

while((found == false) && (i<cantidad)){
          if(l[i].genero == gen){
            found = true;
          }
          i++;   
          if(found == true){
	      aux=l[i-1]; 
	      escribirLibro(aux); 
		  found=false;     
          }
            
        }


}

void busquedaIdioma(Libro l[], int cantidad, string idi){
int i;
bool foundtwo = false;
i=0;
Libro auxi;
   
        while((foundtwo == false) && (i<cantidad)){
          if(l[i].idioma == idi){
            foundtwo = true;
          }
          i++;   
          if(foundtwo == true){
	      auxi=l[i-1]; 
	      escribirLibro(auxi); 
		  foundtwo=false;     
          }
            
        }
    
}

void reemplazoCaracter(Libro l[], int cantidad, char reemplazar, char reemplazara){
	for(int i=0;i<cantidad;i++){
		for(int j=0;j<l[i].editorial.size();j++){
		    if(l[i].editorial[j]==reemplazar){
		    l[i].editorial[j]=reemplazara;
		    }
	    }
	}			
}
