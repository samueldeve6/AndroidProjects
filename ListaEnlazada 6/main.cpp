#include<iostream>
using namespace std;
struct node{
	int num;
	node *next,*pro;
};
node *head,*p,*q,*e;
 // La función insertada antes del primer nodo después del encabezado
void cha1(node *he,node *pc){
	he->next->pro=pc;
	pc->next=he->next;
	pc->pro=he;
	he->next=pc;
}
 // Insertar un nodo antes de un nodo
void cha2(node *find,node *pc){
	find->pro->next=pc;
	pc->pro=find->pro;
	pc->next=find;	
	find->pro=pc;
}
 // Inserta el nodo hasta el final
void cha3(node *final,node *pc){
	final->next=pc;
	pc->pro=final;
	pc->next=NULL;
}
int main(){
	int i=0;
	 // Cree un nodo principal (el nodo principal no tiene valor, por conveniencia)
	head=new node;
 
	p=new node;
	 // Primero vincula un nodo con el nodo principal externamente
	head->next=p;
	p->pro=head;
	p->next=NULL;
	 // Ingrese el valor del nuevo nodo
	cin>>p->num;
	 // Si comienza en 0, termina directamente
	if(p->num==0)return 0;
 
	q=p;
 
	while(1)
	{
	 int flag1 = 1, flag2 = 1; // Establecer una bandera, si cha1 se ha ido, cha2 y cha3 no se usarán, los dos últimos son iguales
	
	p=new node;
	p->pro=NULL;
	p->next=NULL;
	cin>>p->num;
 
	 if (p-> num == 0) break; // Si es 0 entonces salta
 
if(head->next->num>p->num)
{
	flag2=0;
	cha1(head,p);
}
else 
{
	e=head->next;
	while(e)
	{
		if(e->num>p->num)
		{
		flag1=0;
		cha2(e,p);
		break; // Creo que el pan de aquí es la clave para recordar, debes salir después de insertar
		}
	e=e->next;
	}
}
 if (flag1 == 1 && flag2 == 1) // si no se insertan cha1 y cha2
{
	e=head->next;
	while(e->next){
		e=e->next;
	}
	cha3(e,p);
}
}
	e=head->next;
	while (e)
	{
		cout<<e->num<<" "; 
		e=e->next;
	}
}
