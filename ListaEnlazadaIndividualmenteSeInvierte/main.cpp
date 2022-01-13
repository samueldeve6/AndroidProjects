#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int val;
    Node* next;
};
int n;
Node * Create(Node* head)
{
    cin >> n;
    Node *head1 = head;
    for(int i = 0 ; i < n ; i++)
    {
        int x;
        cin >> x;
        if(i==0)
        {
            head1->val = x;
        }
        else
        {
            Node *temp = new Node();
            temp->val = x;
            head1->next = temp;
            head1 = head1->next;
        }
    } 
    return head;
}
void show(Node *head)
{
    if(!n) return ;
    while(head != NULL)
    {
        cout<<"->"<<head->val;
        head = head -> next;
    }
}
Node* Reverse(Node *head)
{
    Node *p = head; //punto anterior
         Node *q = head-> next; //El punto que se está procesando
         Node *r = head; //Siguiente punto
         head-> next = NULL; //El siguiente del puntero de cola está vacío después de la inversión
    while(q != NULL)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    return p;
}
 
int main()
{
    Node* head = new Node();
    Node* last = new Node();
    last = Create(head);
    show(Reverse(last));
}
