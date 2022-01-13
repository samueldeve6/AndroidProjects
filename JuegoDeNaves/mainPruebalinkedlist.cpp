#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
typedef int ComponentType;
struct NodeType; // Declaración directa
typedef NodeType* NodePtr;
struct NodeType
{
ComponentType component;
NodePtr link;
};
NodePtr head; // Puntero externo para la lista
NodePtr newNodePtr; // Puntero para el nodo más reciente
NodePtr currPtr; // Puntero para el último nodo
ComponentType inputVal;
head = new NodeType;
cin >> head->component;
currPtr = head;
cin >> inputVal;
while (cin)
{
newNodePtr = new NodeType; // Create new node
newNodePtr->component = inputVal; // Set its component value
currPtr->link = newNodePtr; // Link node into list
currPtr = newNodePtr; // Set currPtr to last node
cin >> inputVal;
}
currPtr->link = NULL;




	return 0;
}
