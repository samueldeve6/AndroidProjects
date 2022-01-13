#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
  
// Structure for a Singly Linked List
struct node {
    string data;
    node* next;
};
  
// Function to add a new node to the Linked List
node* add(char data)
{
    node* newnode = new node;
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
  
// Function to convert the string to Linked List.
node* string_to_SLL(string text, node* head)
{
    head = add(text[0]);
    node* curr = head;
  
    // curr pointer points to the current node
    // where the insertion should take place
    for (int i = 1; i < text.size(); i++) {
        curr->next = add(text[i]);
        curr = curr->next;
    }
    return head;
}
  
// Function to print the data present in all the nodes
void print(node* head)
{
    node* curr = head;
    while (curr != NULL) {
        cout<< curr->data;
        curr = curr->next;
    }
}

/*void deleteChar(node *&head, char c){
	node *x=head;
	int posicion;
	while(x!=NULL){
		posicion=x->data.find(c);
		while(posicion<x->data.length()){
			x->data.erase(posicion,1);
	     	posicion=x->data.find(c);
		}
		x=x->next;
	}
}*/



/*void deleteChar(node *&head, char c){
	node *x=head;
	int posicion;
	while(x!=NULL){
		posicion = x->data.find(c);
		while(posicion<x->data.length()){
			x->data.replace(x->data.find(c),1,"");
		}
		x=x->next;
	}
}*/

void deleteChar(node *&head, char c){
	node *x=head;
	while(x!=NULL){
		 x->data.erase(remove(x->data.begin(), x->data.end(), c), x->data.end());
		 x=x->next;
	}
}




// Driver code
int main()
{
	char c;
    char text[30];
    cout<<"Ingrese una frase: "<<endl;
    cin.get(text,30);
    node* head = NULL;
    head = string_to_SLL(text, head);
    cout<<"La frase es: ";
    print(head);
    cout<<endl;
    cout<<"Ingrese el caracter a eliminar: ";
    cin>>c;
    deleteChar(head, c);
    print(head);
    
    return 0;
}
   
   
   
   

   
   
   
