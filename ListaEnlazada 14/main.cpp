#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define LEN sizeof(struct LNode)
struct LNode{
	int data;
	struct LNode *next;
};
typedef struct LNode LNode,* LinkList;
 
// Inicializar
LinkList InitLNode(void){
	LinkList head = (LinkList)malloc(LEN);
	if(!head){
		 printf ("Falló la asignación de espacio de almacenamiento! \ n");
		exit(ERROR); 
	}
	head->data = 0;
	head->next = NULL;
	return head;
} 
 // Crea una lista enlazada individualmente en orden inverso
int transCreat(LinkList head){
	LinkList pnew;
	pnew = (LinkList)malloc(LEN);
	 printf ("Ingrese los datos en secuencia (input-1 para terminar) \n");
	scanf("%d",&pnew->data);
	 while (pnew-> data!= -1) {// Primero coloca la cadena en la parte posterior y luego la cadena en la parte delantera 
		head->data++;
		 pnew-> next = head-> next; // declaración central 
		 head-> next = pnew; // Declaración central 
		pnew = (LinkList)malloc(LEN);
		scanf("%d",&pnew->data);
	}
	 free (pnew); // El campo de datos pnew en este momento contiene -1 y no está vinculado a la lista vinculada. 
	return OK; 
}
 // Salida de la lista vinculada individualmente
int printLNode(LinkList head){
	if(!head->next){
		 printf ("¡Lista enlazada vacía! \n");
		return ERROR;
	}	
	LinkList p;
	p = head->next;
	do{
		printf("%d ",p->data);
		p = p->next	;
	}while(p);
}
 // insertar
int insertLNode(LinkList head,int num,int locate){
	if(locate<1||locate>head->data+1){
		 printf ("¡Ubicación de inserción incorrecta! \n");
		exit(ERROR);
	}
	LinkList pnew,p;
	int i=0;
	 p = head; // p apunta al nodo 0 i también significa el nodo 0 
	pnew = (LinkList)malloc(LEN);
	pnew->data = num;
	 while (p && i<locate-1) {
	 //p se detiene en la posición anterior a la posición que se va a insertar 
		p = p->next;
		 i ++; // p se mueve hacia atrás i a medida que el cursor de posición aumenta en 1 
	}
	pnew->next = p->next;
	p->next = pnew;
	head->data++;
	return OK;
}
 // Eliminar 
int delLinkList(LinkList head,int locate){
	if(!head->next){
		 printf ("¡Lista enlazada vacía! \n");
		exit(ERROR); 
	}
	if(locate<1||locate>head->data){
		 printf ("¡La ubicación es incorrecta! \n");
		return ERROR; 
	}
	LinkList pleft,pright;
	int i = 0;
	pleft = pright = head;
	while(pright&&i<locate){
		pleft = pright;
		pright = pright->next;
		 i ++; // pright y me refiero al mismo nodo 
	}
	pleft->next = pright->next;
	head->data--; 
	free(pright);
	return OK; 
}
 
main(){
	LinkList head;
	head = InitLNode();
	transCreat(head);
	printLNode(head);
	 printf ("\n\nInserte un valor de 999 antes del quinto elemento de la lista vinculada individualmente y el resultado es: \n"); 
	insertLNode(head,999,5);
	printLNode(head);
	 printf ("\n\nDespués de eliminar el quinto elemento de la lista vinculada individualmente, el resultado es: \n");
	delLinkList(head,5);
	printLNode(head);
}
