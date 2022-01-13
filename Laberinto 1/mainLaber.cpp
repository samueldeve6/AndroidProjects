#include<iostream>
#include<malloc.h>
#define maxsize 100 
#define N 16
using namespace std;
typedef struct{
	int i;                             //La fila del cuadrado actual 
	int j;                             //La columna del cuadrado actual 
	int num;                           //El número de dirección del siguiente cuadrado adyacente 
}box;
typedef struct{
	box data[maxsize];
	int top;
}stock;

bool path(int mg[N][N],int xi,int yi,int se,int ye)//Coordenadas del punto inicial y final 
{
	int i,j,k,di,find;
	int o,p;
	stock st;
	st.top=-1;// Definir stack st e inicializar 
	st.top++;// El bloque inicial está cerca de la pila 
	st.data[st.top].i=xi;
	st.data[st.top].j=yi;
	st.data[st.top].num=-1;
	mg[xi][yi]=-1;// Cuando se coloca un bloque en la pila, cambia el valor del laberinto a -1; el propósito es evitar la duplicación 
	while(st.top>-1)
	{
		i=st.data[st.top].i;
		j=st.data[st.top].j;
		di=st.data[st.top].num;
		
		if (i == se && j == ye) // Si el elemento superior eliminado es exactamente el punto final
		{
			printf ("El camino del laberinto es el siguiente: \n");
			for(k=0;k<=st.top;k++)
			{
				printf("\t(%d,%d)",st.data[k].i,st.data[k].j);
				if((k+1)%5==0)
					printf("\n");
			}
			printf("\n");
			return true; // devuelve true si se encuentra una ruta
		}
		find=0;
		while(di<4&&find==0)
		{
			di++;
			switch(di)
			{
				case 0:i=st.data[st.top].i-1;j=st.data[st.top].j; break;
				case 1:i=st.data[st.top].i;j=st.data[st.top].j+1; break;
				case 2:i=st.data[st.top].i+1;j=st.data[st.top].j; break;
				case 3:i=st.data[st.top].i;j=st.data[st.top].j-1; break;
			}
			if(mg[i][j]==0){find=1;} // Encontré el siguiente cuadrado transitable (i, j) 
		}
		if(find==1)
		{
			st.data[st.top].num=di;
			st.top++;
			st.data[st.top].i=i;
			st.data[st.top].j=j;
			st.data[st.top].num=-1;
			mg[i][j]=-1;
		}
		else
		{
			mg[st.data[st.top].i][st.data[st.top].j]=0;
			st.top--;
		}
	 }
	 return false;
	 // No se encontró la ruta correcta 
}


int main()
{
	int mg[N][N]={                  // Dibuja el laberinto
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1},
		{1,0,0,1,0,1,0,1,0,0,1,0,1,0,0,1},
		{1,0,0,0,0,1,0,0,0,0,1,0,1,1,1,1},
		{1,0,1,1,1,1,0,1,0,0,0,0,0,0,1,1},
		{1,0,0,0,0,0,0,1,0,1,1,0,0,1,0,1},
		{1,0,1,1,1,1,1,1,0,0,1,1,0,0,0,1},
		{1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
		{1,0,1,1,1,0,1,0,0,1,0,0,0,0,0,1},
		{1,1,0,1,0,0,1,0,1,0,0,0,0,1,0,1}, 
		{1,0,0,0,0,1,1,0,0,0,1,0,0,1,1,1}, 
		{1,0,1,1,0,1,0,0,0,0,1,1,0,1,0,1}, 
		{1,0,1,0,1,0,0,1,0,0,1,0,0,0,0,1}, 
		{1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 
	};
	int xi,yi,se,ye,p,q;
	cout<<"Introduzca las coordenadas del punto de partida:";
	cin>>xi>>yi;
	cout<<"Introduzca las coordenadas de la salida:";
	cin>>se>>ye;
	path(mg,xi,yi,se,ye); 
	
	for(p=0;p<16;p++)
	 {
	 	for(q=0;q<16;q++)
	 	{
	 	    switch(mg[p][q]){
	 		case 1:printf("%c ",254); break;
			case 0:cout<<"  "; break;
			case -1:cout<<"* "; break;
			}	
		 } 
		 cout<<"\n";
	 }
	 cout<<"\n";
	 printf("%c: Obstaculo *: Ruta",254);
	 
 } 

