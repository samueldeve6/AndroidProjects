#include <stdio.h>
#include <stdlib.h>
typedef struct node// Definir estructura de nodo de lista de enlace de datos 
{
 int data;// campo de datos 
 struct node *next;// campo de puntero 
}Node;

int main(void)
{
 Node *head;// El puntero principal de la lista vinculada almacena la direcci�n del primer nodo
 Node  *p=(Node *)malloc(sizeof(Node));// Crea el primer nodo en la memoria din�mica
 head=p;// p-> nodo (datos, * siguiente) 
 p->data=20;
 
 Node *q=(Node *)malloc(sizeof(Node));// Crear un segundo nodo en memoria din�mica
 p->next=q;
 q->data=30;
 q->next=NULL;
 
 printf("El valor del puntero principal de la lista vinculada es:% # X \ n",head);//% # X: n�mero hexadecimal de salida del prefijo 
 
 printf("La direcci�n del nodo de la lista vinculada es:");
 for(Node *i=head;i!=NULL;i=i->next)// Recorrer la lista vinculada y generar la direcci�n de cada nodo 
 {
  printf(" %#X  ",i);
 }
 printf("\n");
 printf("Los datos del nodo de la lista vinculada son:");
 for(Node *i=head;i!=NULL;i=i->next)// Recorrer la lista y generar el valor de cada nodo (campo de datos y campo de puntero) 
 {
  printf("% d (campo de datos)% # X (campo de puntero)",i->data,i->next);
 }
 return 0; 
} 
