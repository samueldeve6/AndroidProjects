#include <iostream>
#include <conio.h>
using namespace std;
/*
    Lizeth Dayana Manrique Hidalgo
    Samuel Remolina Alvarez
    Grupo:402
*/

int main(int argc, char** argv) {
	int  i,j,k;
	int  fa,ca,fb,cb;
    //ingresar el numero de filas y columnas de A
	cout<<"Ingrese el numero de filas de A: ";
	cin>>fa;
	cout<<"Ingrese el numero de columnas de A: ";
	cin>>ca; 
	//ingresar el numero de filas y columnas de B
    cout<<"Ingrese el numero de filas de B: ";
	cin>>fb;
	cout<<"Ingrese el numero de columnas de B: ";
	cin>>cb; 
	
	int A[fa][ca], B[fb][cb], C[fa][cb];
	if(ca==fb){
	    //llenar datos de la matriz A	
		cout<<"Ingrese los datos de A"<<endl;
		for(i=0;i<fa;i++){
		    for(j=0;j<ca;j++){
			     cout<<"A["<<i<<"]["<<j<<"]: ";
			     cin>>A[i][j];
		    }
	    }
	    //llenar datos de la matriz B
	    cout<<"\nIngrese los datos de B"<<endl;
		for(i=0;i<fb;i++){
		    for(j=0;j<cb;j++){
			     cout<<"B["<<i<<"]["<<j<<"]: ";
			     cin>>B[i][j];
			 }
		}
		//multiplicación de ambas matrices
		for(i=0;i<fa;i++){
			for(j=0;j<cb;j++){
				C[i][j]=0;
				for(k=0;k<ca;k++){
					C[i][j] += A[i][k]*B[k][j];
				}
			}
		}
		cout<<endl;
		//mostrar matriz resultante
		for(i=0;i<fa;i++){
			for(j=0;j<cb;j++){
			cout<<C[i][j]<<" ";
			}
			cout<<endl;
		}
    }
    getch();
	return 0;
}
