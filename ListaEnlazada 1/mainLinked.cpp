#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *link;
};
typedef Node *nodePtr;
void insert(nodePtr &, int);
void print(nodePtr &);
Node* reverse(Node *);
void show(Node *);
int main(){
	int number;
	char caracter;
	nodePtr head;
	while(caracter!='n'){
		cout<<"Ingrese un valor a la lista"<<endl;
		cin>>number;
		insert(head,number);
		
		cout<<"Desea ingresar mas valores (s/n)"<<endl;
		cin>>caracter;
		if(caracter=='n') break;}
	show(reverse(head));}

void insert(nodePtr& head, int data){
	nodePtr temp;
	temp = new Node;
    temp->data= data;
	temp->link = head;
	head = temp;}

Node* reverse(Node *head){
    Node *p = head; //punto anterior
         Node *q = head->link; //El punto que se está procesando
         Node *r = head; //Siguiente punto
         head->link = NULL; //El siguiente del puntero de cola está vacío después de la inversión
    while(q != NULL){
        r = q->link;
        q->link = p;
        p = q;
        q = r; }
    return p;}

void show(Node *head){
    while(head != NULL){
        cout<<"->"<<head->data;
        head = head->link;}}
