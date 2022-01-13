#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>

using namespace std;
/*
	   
*/

int main() {
	string frase[2];
	string numero[2];
	int i;
	
	cout<<"Digite la frase: ";
	getline(cin,frase[0]);
	
	cout<<"Digite la clave: ";
	getline(cin,numero[0]);
	
	for(i=0;i<frase[0].length();i++){
		numero[1]+=numero[0];
		if (numero[1].length()==frase[0].length()){
			break;
		}
    }
	cout<<"La frase es:"+frase[0]+"\n";
    cout<<"La clave es: "+numero[1]+"\n";
	cout<<"La frase cifrada es: ";
	for(i=0;i<frase[0].length();i++){
	cout<<(char)(frase[0][i]+(int)(numero[1][i]-'0'));	
		}
		return 0;
	}
	
	
	
  
	


	
	
	

