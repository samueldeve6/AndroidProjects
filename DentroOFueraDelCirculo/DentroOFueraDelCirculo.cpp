#include<iostream>
//Presentado por: Lizeth D. Manrique - Samuel Remolina Alvarez
using namespace std;

int main(){
//Variables a usar
int vector[1000];    //Se define el vector donde se van a guardar todos los puntos
int circulo[2];		//aqui se guardan las coordenadas del centro del circulo
int radio;			//para guardar el radio del circuilo
int Rcuadrado;		
char respuesta[2];
int i=2;
char si[2]={'s','i'};	
double PuntoX;
double PuntoY;
double res;

	cout<<"INGRESE LA POSICION DEL CENTRO DEL CIRCULO"<<endl; //aviso para el usuario 
	cout<<"x=";cin>>circulo[0]; // se guarda en la posicion 0 la coordenada x del centro del circulo
	cout<<"y=";cin>>circulo[1]; // se guarda en la posicion 1 la coordenada y del centro del circulo

	cout<<"INGRESE EL RADIO DEL CIRCULO"<<endl;
	cin>>radio;		//se recibe y guarda el valor del radio del circulo

	cout<<"INGRESE LA POSICION DE UN PUNTO"<<endl;
	cout<<"x=";cin>>vector[0];	//se guarda en la posicion 0 la coordenada x del primer punto
	cout<<"y=";cin>>vector[1];	//se guarda en la posicion 1 la coordenada y del primer punto
	
	cout<<"¿DESEA INGRESAR OTRO PUNTO? Responda si o no"<<endl;
	cin>>respuesta; //se pregunta al usuario si quiere agregar mas puntos y se guarda la respuesta
	
	
	while(respuesta[0]==si[0] ){  //se abre un ciclo mientras el usuario responda "si" a la pregunta de si quiere ingresar otro punto
	
	cout<<"x=";cin>>vector[i]; //se inica i en 2 y aqui se guarda las coordenadas x de cada punto 
	cout<<"y=";cin>>vector[i+1]; //en la posicion i+1 se van guardando las coordenada y de cada punto

	cout<<"¿DESEA INGRESAR OTRO PUNTO? Responda si o no"<<endl;
	
	cin>>respuesta;  //se vuelve a preguntar al usuario si quiere agregar otro punto y se guarda la respuesta
	
	i=i+2;  //i va aumentando de a 2 unidades para nos sobre escribir el vector
	
	} // cuando el usuario responda que ya no quiere ingresar mas puntos se acaba el while
	
	
for(int a=0;a<i;a=a+2){   // se inicia un ciclo desde cero hasta el valor de i
	
	
	// (xDelPunto - xDelCirculo)^2 + (yDelPunto - yDelCirculo)^2 = radio^2
	
	PuntoX = ((vector[a]-circulo[0])*(vector[a]-circulo[0]));  // se calcula la distancia en el eje x desde la posicion del circulo a cada punto
	PuntoY = ((vector[a+1]-circulo[1])*(vector[a+1]-circulo[1])); // se calcula la distancia en el eje y desde la posicion del circulo a cada punto
	res = PuntoX+PuntoY; //se suman los resultados anteriores
	Rcuadrado=radio*radio; // se eleva el radio del circulo al cuadrado
	
	if (res<Rcuadrado){ // pregunta si la operacion de arriba es menor al cuadrado del radio
		
		cout<<"El punto "<<vector[a]<<","<<vector[a+1]<<" esta dentro del circulo"<<endl;	//imprime cada coordenada que este dentro del radio del circulo
		
	}
	
}

return 0;

}
