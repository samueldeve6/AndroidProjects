#include<iostream>
 
using namespace std;
 
typedef struct LNode{
	 int data; // campo de datos 
	 struct LNode * next; // Campo de puntero 
}LNode,*Linklist;
 
bool InitList(Linklist &L)
{
	L=new LNode;
	L->next=NULL;
	L->data=0;
	return true;
}
 
bool GetElem(Linklist &L,int i,int &e)
{
	LNode *p=L->next;
	int j=1;
	while(p&&j<i)
	{
		p=p->next;
		j++;
	}
	if(!p||j>i)
		return false;
	e=p->data;
	return true;
}
 
 // Insertar encabezado para crear una lista vinculada 
void CreateList_H(Linklist &L,int n)
{
	L=new LNode;
	L->next=NULL;
	L->data=0;
	for(int i=0;i<n;i++)
	{
		int m;
		LNode *p=new LNode;
		cin >> m;
		p->data=m;
		p->next=L->next;
		L->next=p; 
		L->data++;
	}
}
 
 // Fin de la inserción 
void CreateList_R(Linklist &L,int n)
{
	L=new LNode;
	L->data=0;
	L->next=NULL;
	LNode *r;
	r=L;
	for(int i=0;i<n;i++)
	{
		int m;
		LNode *p=new LNode;
		cin >> m;
		p->data=m;
		p->next=NULL;
		r->next=p;
		r=p;
		L->data++;
	}
}
 
 //Insertar
bool ListInsert(Linklist &L,int i,int e)
{
	LNode *p=L;
	int j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(!p||j>i-1)
		return false;
	LNode *s=new LNode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	L->data++;
	return true;
} 
 
bool ListDelete(Linklist &L,int i)
{
	LNode *p=L;
	int j=0;
	while(p->next&&j<i-1)
	{
		p=p->next;
		j++; 
	} 
	if(!(p->next)||j>i-1)
		return false;
	 LNode * q; // almacena p-> siguiente para publicarlo más tarde 
	q=p->next;
	p->next=q->next;
	L->data--;
	delete q;
	return true;
}
 
 //Localizar
int LocateElem(Linklist L,int e)
{
	LNode *p=L->next;
	int j=1;
	while(p&&p->data!=e)
	{
		p=p->next;
		j++;
	}
	if(j>L->data)
		return false;
	return j;
 } 
 
void ClearList(Linklist &L)
{
	LNode *p,*q;
	p=L->next;
	while(p)
	{
		q=p->next;
		delete p;
		p=q;
	}
	L->next=NULL;
}
 
int main()
{
	 cout << "----- Realización simple de lista enlazada individualmente: ---- \n"
		  << "1. Inicialización de la lista vinculada \n"
		  << "2, inserta \n" 
		  << "3. Cree una lista vinculada de n números \n"
		  << "4. Finalice las inserciones para crear una lista vinculada de n números \n"
		  << "5, eliminar \n"
		  << "6, valor \n"
		  << "7, posicionamiento \n"
		  << "8. Destruye \ n"
		  << "0, salir del sistema \n";
	int n;
	Linklist L;			
	while(1)
	{
		int num;
		int j,k;
		cout << "-------------------------------------\n";
		 cout << "Por favor ingrese la operación que desea realizar:";
		cin >> n;
		switch(n)
		{
			case 1:
				if(InitList(L))
					 cout << "¡La lista enlazada se ha inicializado correctamente! \n";
				break;
			case 2:
				 cout << "Introduzca la posición a insertar y el elemento de datos a insertar:";
				cin >> j >> k;
				if(ListInsert(L,j,k))
					 cout << "¡Insertar correctamente! \n";
				else 
					 cout << "¡La posición de inserción es ilegal! \n";
				break;
			case 3:
				 cout << "Introduzca cuántos números desea almacenar:";
				cin >> num;
				CreateList_H(L,num);
				break; 
			case 4:
				 cout << "Introduzca cuántos números desea almacenar:";
				cin >> num;
				CreateList_R(L,num);
				break;
			case 5:
				 cout << "Introduzca el número de elementos que desea eliminar:";
				cin >> j;
				if(ListDelete(L,j))
					 cout << "¡Eliminar correctamente! \n";
				else	
					 cout << "¡La ubicación de eliminación es ilegal! \n";
				break;
			case 6:
				 cout << "Por favor ingrese el elemento en la posición que desea tomar:";
				cin >> j;
				if(GetElem(L,j,k))
					 cout << "th" << j << "El elemento en la posición es" << k << endl;
				else
					 cout << "¡La posición es ilegal! \n";
				break; 
			case 7:
				 cout << "Introduzca el valor que busca:";
				cin >> k;
				num=LocateElem(L,k);
				if(num)
					 cout << "en el primer" << num << "uno! \n";
				else 
					 cout << "¡No se encontró el valor! \n";
				break;
			case 8:
				 cout << "¡La lista vinculada ha sido destruida! ¡Salga del programa automáticamente! \n";
				exit(0);
			default :
				exit(0);
				
		}
		cout << "--------------------------------------------\n";
		 cout << "La longitud de la lista enlazada actual es" << L-> data << "! \ n";
		 cout << "La información digital de la lista enlazada actual es: \ n";
		for(int i=1;i<=L->data;i++)
		{
			int e;
			GetElem(L,i,e);
			cout << e << "  ";
		}
		cout << "\n";
	}	
	return 0;
} 
