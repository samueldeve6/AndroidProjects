#include<iostream>
#include<stdio.h>
#include<stdlib.h>
//Presentado por: Lizeth D.Manrique Hidalgo-Samuel Remolina Alvarez-402


using namespace std;
int main(){
 
	int n;  //variable del tamaño de la sopa de letras

	cout<<"Ingrese el tamano de la sopa de letras: ";		//se le pide al usuario ingresar el tamaño de la sopa de letras
	cin>>n;			//se recibe el valor del tamaño de la sopa de eltras

	char sopa[n][n];		//se crea una matriz cuadrada de tamaño nxn con el valor ingresado por el usuario

	char letras[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
					   'n','o','p','q','r','s','t','u','v','w','x','y','z'};		//se ingresan las letras del abecedario
					   
	for (int i=0;i<n;i++){		//Variamos la filas desde 0 hasta n
		for (int j=0;j<n;j++){	//Variamos las columnas desde 0 hasta n
			sopa[i][j]=letras[ rand() % 26]; //le asignamos a cada posicion de la matriz una letra aleatoria
		}
	}
	
	int T1,T2,T3,T4,T5,T6,T7,T8,T9,T10; //variables para guardar el tamaño de las palabras
	int q=0;
	//Variables para guardar las palabras
	char primera[n];
	char segunda[n];
	char tercera[n];
	char cuarta[n];
	char quinta[n];
	char sexta[n];
	char septima[n];
	char octava[n];
	char novena[n];
	char decima[n];
	
	
	cout<<"Ingrese 10 palabras"<<endl;		//le pedimos 10 palabras al usuario
	
	cout<<"\nPalabra 1: ";		//Damos 1 reglon de espacio y pedimos 1 palabra al usuario
	cin>>primera;		//guardamos la palabra
	cout<<"Cuantas letras tiene "<<primera<<" : ";	//preguntamos cuantas letras tiene la palabra
	cin>>T1;		//guardamos el tamaño de la palabras

	cout<<"\nPalabra 2: ";		//Damos 1 reglon de espacio y pedimos 1 palabra al usuario
	cin>>segunda;		//guardamos la palabra
	cout<<"Cuantas letras tiene "<<segunda<<" : ";	//preguntamos cuantas letras tiene la palabra
	cin>>T2;		//guardamos el tamaño de la palabras
	
	cout<<"\nPalabra 3: ";		//Damos 1 reglon de espacio y pedimos 1 palabra al usuario
	cin>>tercera;		//guardamos la palabra
	cout<<"Cuantas letras tiene "<<tercera<<" : ";	//preguntamos cuantas letras tiene la palabra
	cin>>T3;		//guardamos el tamaño de la palabras

	cout<<"\nPalabra 4: ";		//Damos 1 reglon de espacio y pedimos 1 palabra al usuario
	cin>>cuarta;			//guardamos la palabra
	cout<<"Cuantas letras tiene "<<cuarta<<" : ";	//preguntamos cuantas letras tiene la palabra
	cin>>T4;		//guardamos el tamaño de la palabras

	cout<<"\nPalabra 5: ";		//Damos 1 reglon de espacio y pedimos 1 palabra al usuario
	cin>>quinta;			//guardamos la palabra
	cout<<"Cuantas letras tiene "<<quinta<<" : ";	//preguntamos cuantas letras tiene la palabra
	cin>>T5;		//guardamos el tamaño de la palabras

	cout<<"\nPalabra 6: ";		//Damos 1 reglon de espacio y pedimos 1 palabra al usuario
	cin>>sexta;			//guardamos la palabra
	cout<<"Cuantas letras tiene "<<sexta<<" : ";	//preguntamos cuantas letras tiene la palabra
	cin>>T6;		//guardamos el tamaño de la palabras

	cout<<"\nPalabra 7: ";		//Damos 1 reglon de espacio y pedimos 1 palabra al usuario
	cin>>septima;		//guardamos la palabra
	cout<<"Cuantas letras tiene "<<septima<<" : ";	//preguntamos cuantas letras tiene la palabra
	cin>>T7;		//guardamos el tamaño de la palabras

	cout<<"\nPalabra 8: ";		//Damos 1 reglon de espacio y pedimos 1 palabra al usuario
	cin>>octava;		//guardamos la palabra
	cout<<"Cuantas letras tiene "<<octava<<" : ";	//preguntamos cuantas letras tiene la palabra
	cin>>T8;		//guardamos el tamaño de la palabras

	cout<<"\nPalabra 9: ";		//Damos 1 reglon de espacio y pedimos 1 palabra al usuario
	cin>>novena;		//guardamos la palabra
	cout<<"Cuantas letras tiene "<<novena<<" : ";	//preguntamos cuantas letras tiene la palabra
	cin>>T9;		//guardamos el tamaño de la palabras

	cout<<"\nPalabra 10: ";		//Damos 1 reglon de espacio y pedimos 1 palabra al usuario
	cin>>decima;			//guardamos la palabra
	cout<<"Cuantas letras tiene "<<decima<<" : ";	//preguntamos cuantas letras tiene la palabra
	cin>>T10;		//guardamos el tamaño de la palabras


//tercera palabra DIAGONAL
	for (int i=0;i<1;i++){		//se deja la fila fija
		for (int j=0;j<T3;j++){ //se varia la columna desde 0 hasta el tamaño de la palabra
			sopa[i][j]=tercera[j];	//se va escribiendo la palabra
			i=i+1;		//se va aumentando la fila
		}
	}
	


//primera palabra HORIZONTAL
	for (int i=n-3; i<n-2;i++){		//se deja la fila fija
		for (int j=1;j<T1+1;j++){	//se varia la columna desde 1 hasta el tamaño de la palabra + 1
			sopa[i][j]=primera[j-1];	//se va escribiendo la palabra
		}
	}

//segunda palabra HORIZONTAL
	for (int i=n-1;i<n;i++){				//se deja la fila fija
		for (int j=(n-(n-2));j<T2+2;j++){		//se varia la columna
			sopa[i][j]=segunda[j-2];		//se va escribiendo la palabra letra por letra
		}
	}
	

//cuarta palabra VERTICAL
	
	for (int i=n-1;i<n;i++){		//se deja la columna fija
		for (int j=0;j<T4;j++){		//se va variando la fila desde 0 hasta el tamaño de la palabra
			sopa[j][i]=cuarta[j];		//se va escribiendo la palabra letra por letra
		}
	}

//quinta palabra INVERTIDA
	
	for (int i=n-3;i<n-2;i++){		//se deja la columna fija
		for (int j=2;j<T5+2;j++){	//se va variando la fija desde 2 hasta el tamaño de la palabra +2
			sopa[j][i]=quinta[(T5+1)-j]; //se va escribiendo la palabra letra por letra
		}
	}
	
//sexta palabra INVERTIDA
	
	for (int i=n-4;i<n-3;i++){		//se deja la columna fija
		for (int j=2;j<T6+2;j++){	// se varia la fila desde 2 hasta el tamaño de la palabra +2
			sopa[j][i]=sexta[(T6+1)-j];		//se va escribiendo la palabra desde el final al comienzo 
		}
	}

//septima palabra HORIZONTAL
	for (int i=0; i<1;i++){		//se deja la fila fija
		for (int j=2;j<T7+2;j++){		//se varia la colunma
			sopa[i][j]=septima[j-2];	//se va escribiendo la palabra letra por letra
		}
	}

//octava palabra DIAGONAL
	for (int i=4;i<5;i++){		//se deja la fila fija
		for (int j=3;j<T8+3;j++){		//se varia la columna
			sopa[i][j]=octava[j-3];	//se va escribiendo la palabra letra por letra
			i=i+1; //se va aumentando la fila dentro del ciclo de las columnas
		}
	}

//novena palabra VERTICAL
	for (int i=0;i<1;i++){		//	Se dejan las columnas fijas
		for (int j=1;j<T9+1;j++){	//se varian las filas
			sopa[j][i]=novena[j-1];	//se va escribiendo letra por letra de la palabra
		}
	}

 //decima palabra DIAGONAL
	for (int i=n-2;i<n-1;i++){			//se deja fija la fila
		for (int j=(n-(n-1));j<T10+1;j++){		//se varia la columna
			sopa[i][j]=decima[j-1];		//se va escribiendo la plabra letra por letras
		}
	}


//mostrar la sopa de letras
	cout<<"\nLa sopa de letras es: "<<"\n"<<endl; //se muestra el letrero
	for (int i=0;i<n;i++){		//se va variando las filas desde 0 hasta el tamaño de la matriz 
		for (int j=0;j<n;j++){	//se va variando las columnas desde 0 hasta el tamañao de la matriz
			cout<<" "<<sopa[i][j]; //se va imprimiendo la sopa de letras
		}
		cout<<endl;
	}


	return 0;			//se devuelve cero
}
