#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node* pre;
};
int n;
Node* Create(Node* head)
{
    cin >> n;
    Node *head2 = head;
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
            temp->pre = head1;
            head1->next = temp;
            head1 = head1->next;
                         if (i == n-1) // primer lugar
            {
                head2->pre = head1;
                head1->next = head2;
            }
        }
 
    }
 
    return head1;
}
void show(Node *last)
{
    if(!n) return;
    while(last!=NULL)
    {
        cout << last->val << endl;
        if(last->pre != NULL) last = last->pre;
        else break;
    }
}
int main()
{
    Node* head = new Node();
    Node* last = new Node();
    last = Create(head);
    system("pause");
    show(last);
    
}
