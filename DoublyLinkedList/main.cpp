#include <iostream>
using namespace std;

/*

     INTRODUCTION TO DOUBLY LINKED LIST

Doubly Linked List - Doubly Linked List is a linked list where each node have an additional pointer to the previous node.

*/

/* YOU CAN USE THE BELOW MENTIONED FUNCTIONS USING THE DOT OPERATOR 

EG: LinkedList newll;
    Node newnode = new Node(10);
    newll.addFront(newnode);
*/

//EDT THE MAIN FUNCTION AND TRY DIFFERENT FUNCTIONS

/*
1.isEmpty() - checks whether a linked list is empty or not
2.addFront(Node* node) - add nodes at front
3.printAll() - prints all nodes of a linked list
4.getLast() - returns the last node
5.addLast(Node* node) - add nodes at last
6.getByIndex(int index) - get the address of nodes by its index
7.checkNode(Node* node) - checks whether a given node is present in the linked list or not
8.addAfter(Node* node) - add node after a given node
9.addBefore(Node* oldNode, Node* newNode) - add before a given node
*/

class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
    
};

class LinkedList {
    public:
    Node* head; 
    Node* last;
    LinkedList() {
        head = NULL;
        last = NULL;
    }
    void delNode(Node* node) {
        bool x = checkNode(node);
        if (x) {
            if (node == head) {
                head = head->next;
                head->prev = NULL;
                node->next = NULL;
            } else if (node == last) {
                last = last->prev;
                last->next = NULL;
                node->prev = NULL;
            } else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                node->next = NULL;
                node->prev = NULL;
            }
        } else {}
    }
    void addBefore(Node* oldNode, Node* newNode) {
        bool x = checkNode(oldNode);
        if (!isEmpty() || x) {
            if (oldNode == head) {
                head = newNode;
            } else {
                oldNode->prev->next = newNode;
                newNode->prev = oldNode->prev;
            }
        newNode->next = oldNode;
        oldNode->prev = newNode;
        } else {}
    }
    void addAfter(Node* oldNode, Node* newNode) {
        bool x = checkNode(oldNode);
        if (!isEmpty() || x) {
        if (oldNode->next == NULL) {
            oldNode->next = newNode;
            newNode->prev = oldNode;
            last = newNode;
        } else {
        oldNode->next->prev = newNode;
        newNode->next = oldNode->next;
        newNode->prev = oldNode;
        oldNode->next = newNode;
        }
        } else {}
    }
    bool checkNode(Node* node) {
            Node* curr = head;
            bool x = false;
            while(curr != NULL) {
            if (curr == node) {
                x = true;
                break;
            }
            curr = curr->next;
            }
            if ((curr == NULL) || (node == NULL)) {
                x = false;
            }
            return x;
        }
    Node* getByIndex(int index) {
        if (isEmpty()) {
            return NULL;
        }
        Node* curr = head;
        int i;
        for (i = 0; i < index; i++) {
            curr = curr->next;
            if (curr == NULL) {
                break;
            }
        }
        if (curr != NULL) {
            return curr;
        } else {
            return NULL;
        }
    }
    void addLast(Node* node) {
        if (isEmpty()) {
            head = node;
            last = node;
        } else {
            last->next = node;
            node->prev = last;
            last = node;
        }
        
    }
    void addFront(Node* node) {
        if (!isEmpty()) {
            node->next = head;
            head->prev = node;
        } else {
            last = node;
        }
        head = node;
    }
    bool isEmpty() {
        bool ans = false;
        if (head == NULL) {
            ans = true;
        }
        return ans;
    }
    void printAll() {
            Node* traverser = head;
            while (traverser != NULL) {
                cout << traverser->data << " -> ";
                traverser = traverser->next;
            }
            cout << " " << endl;
        }
};

int main() {
    LinkedList theLL;
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    theLL.addFront(n2);
    theLL.addFront(n1);
    theLL.addLast(n3);
    theLL.printAll();
    delete n1;
    delete n2;
    delete n3;
    return 0;
}
