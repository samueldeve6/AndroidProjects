#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char** argv) {
	char frase[20];
	int clave[20];
	char cifrado[20];
	int tam=0;
	int i=0;
	int j =0;
	
	cout<<"digite la frase original: ";
	cin.getline(frase,20);
	tam = strlen(frase);
	
	cout<< "digite la clave digito a digito (-1 para terminar)";
	do{
		cin>>clave[i];
		i++;
	}while(clave[i-1]!= -1); //PILAS FALTA VALIDAR LONGITUD MAX DE 20
	
	j=i-1;
	i=0;
	while(j<20){
		clave[j]=clave[i];
		j++;
		i++;
	}
	
	for(j=0;j<20;j++){
		cifrado[j]=frase[j]+clave[j]; // falta validar el abecedario circular
	}
	
	for(j=0;j<tam;j++){
		cout<< cifrado[j]<<" ";
	}
	
	
	
	return 0;
}
