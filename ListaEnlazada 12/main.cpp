#include<stdio.h>
#include<malloc.h>
struct node
{
 int data;
 struct node *next; 
};
int icount;
 struct node * creat () // La creación de una lista vinculada
{
 struct node *pnew,*pend,*phead=NULL;
 pend=pnew=(struct node *)malloc(sizeof(struct node));
 printf("data:");
 scanf("%d",&pnew->data);
 icount=0;
 while(pnew->data!=0)
 {
  ++icount;
  if(icount==1)
  {
       phead = pnew; // Si es el primer nodo creado, el puntero de la cabeza apunta a este nodo
  }
  else
  {
       pnew-> next = NULL; // El puntero del nuevo nodo está vacío 
       pend-> next = pnew; // El puntero sucesor del nodo anterior apunta al nodo actual 
       pend = pnew; // El puntero pend apunta al nodo actual 
  }
  pnew=(struct node *)malloc(sizeof(struct node));
  printf("data:");
  scanf("%d",&pnew->data);
 }
   free (pnew); // Libera el nodo
   return phead; // Devuelve el puntero de la cabeza, puede recorrer la lista vinculada cuando encuentre el puntero de la cabeza 
} 
void print(struct node *phead)
{
 struct node *ptemp;
 ptemp=phead;
 printf("output:\n"); 
 while(ptemp!=NULL)
 {
  printf("%d\n",ptemp->data);
  ptemp=ptemp->next;
 }
}
int main()
{
 struct node *phead;
 phead=creat();
 print(phead);
}
