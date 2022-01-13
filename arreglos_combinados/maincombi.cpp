#include <iostream>
#include<conio.h>
using namespace std;
/*
    Integrantes:
    Lizeth Dayana Manrique Hidalgo
    Samuel Remolina Alvarez
    Grupo:402

*/

int main(int argc, char** argv) {
	int vector1[100],vector2[100],vector3[100],vector4[100],vector5[100];
	int i,j,n1,n2,n3;
	int nvector=0,aux=0;
	//lee primer vector
	cout<<"Ingrese el numero de elementos que va a tener el arreglo: ";
	cin>>n1;
	for( i=0;i<n1;i++){
		cout<<"Dato ["<<i<<"]: ";
		cin>>vector1[i];
	}
	//imprime vector
	for( i=0;i<n1;i++){
		cout<<vector1[i]<<" ";
	}
	cout<<endl;
	//lee segundo vector
	cout<<"Ingrese el numero de elementos que va a tener el arreglo: ";
	cin>>n2;
	for( i=0;i<n2;i++){
	    cout<<"Dato ["<<i<<"]: ";
		cin>>vector2[i];
	}
	//imprime vector
	for( i=0;i<n2;i++){
		cout<<vector2[i]<<" ";
	}
	cout<<endl;
	//lee tercer vector 
	cout<<"Ingrese el numero de elementos que va a tener el arreglo: ";
	cin>>n3;
	for(i=0;i<n3;i++){
		cout<<"Dato ["<<i<<"]: ";
		cin>>vector3[i];
	}
	for(i=0;i<n3;i++){
		cout<<vector3[i]<<" ";
	}
	cout<<endl;
	//unir vectores 1 y 2
	for(i=0;i<n1;i++){
		vector4[i]= vector1[i];
	}	
	int nnvector=n1+n2;
	for(i=n1;i<nnvector;i++){
		vector4[i]= vector2[i-n1];
	}
	nvector=n1+n2+n3;	
	for(i=nnvector;i<nvector;i++){
		vector4[i]=vector3[i-nnvector];
	}
	cout<<endl;
	
	//Ordenamiento
	for(j=0;j<nvector-1;j++)
	for(i=0;i<nvector-1;i++){
		if(vector4[i]>vector4[i+1]){
			aux=vector4[i];
			vector4[i]=vector4[i+1];
			vector4[i+1]=aux;
			}		
	}
	//imprimir vector final
	for(i=0;i<=nvector;i++){
		for(j=0;j<i;j++){
				cout<<vector4[j]<<" ";
	}
	cout<<endl;
}

	getch();
	return 0;
}
