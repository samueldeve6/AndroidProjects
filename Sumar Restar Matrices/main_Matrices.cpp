#include <conio.h>
#include <iostream>
using namespace std;

/* 
     Lizeth Dayana Manrique Hidalgo
     Samuel Remolina Alvarez
     Grupo:402
 */

int main(int argc, char** argv) {
	int  m,n,i,j,opcion;
	//ingresar el numero de filas y columnas
	cout<<"Ingrese el numero de filas: ";
	cin>>m;
	cout<<"Ingrese el numero de columnas: ";
	cin>>n;
	// declarar matrices con el tamaño indicado por el usuario
	float a[m][n],b[m][n],c[m][n];
	//llenar matriz A
	cout<<"Ingrese los datos de la matriz A."<<endl;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cout<<"A["<<i<<"]["<<j<<"]: ";
			cin>>a[i][j];
		}
	}
	//Llenar matriz B
	cout<<"Ingrese los datos del a matriz B."<<endl;
	for(i=0;i<m;i++){
	    for(j=0;j<n;j++){
			cout<<"B["<<i<<"]["<<j<<"]: ";
			cin>>b[i][j];
		}
	}
	//Preguntar por la operación que desea realizar
	cout<<"Que operacion desea utilizar? Ingrese 1-Suma, 2-Resta: ";
	cin>>opcion;
	//sumar matrices
	if(opcion==1)
	{
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				c[i][j]=a[i][j]+b[i][j];
			}
		}
	}
	//restar matrices
	else
	if(opcion==2){
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				c[i][j]=a[i][j]-b[i][j];
			}
		}
	}
	
	//Imprimir matriz resultante
    cout<<"La matriz resultante es: "<<endl;
    for(i=0;i<m;i++){
    	for(j=0;j<n;j++){
    		cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
   
	
	getch();
	return 0;
}
