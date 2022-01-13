#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int val;
    Node* next;
};
void Create(Node* head)
{
    int n;
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
}
void show(Node *head)
{
    while(head!=NULL)
    {
        cout<<"->"<<head->val;
        if(head->next != NULL) head = head->next;
        else break;
    }
}
int main()
{
    Node* head = new Node();
    Create(head);
    show(head);
}
