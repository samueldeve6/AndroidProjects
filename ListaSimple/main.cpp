#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

typedef struct node node;

node * Allocate()
{
 node * new_node = NULL;
 new_node = (node *) malloc(sizeof(node *));
 new_node->next=NULL;
 printf("\n");
 printf ("Please enter data.\n");
 scanf ("%d",&new_node->data);
 printf("\n");
 return new_node;
}


node * insert_at_front(node * head)
{
    node * new_node = Allocate();
    new_node->next=head;
    head=new_node;
    return head;
}


node * insert_at_end(node * head)
{
  node * temp=head;
  node * new_node = Allocate();
    if (head==NULL)
       {
        head=new_node;
        return head;
       }

    while(temp->next!=NULL)
        temp=temp->next;
        temp->next=new_node;
    return head;
}


node * delete_from_front(node * head)
{
    node * temp=head;
    head=head->next;
    free(temp);
    return head;
}


node * delete_from_end(node * head)
{
    node * temp = head;
    while (temp->next->next!=NULL)
        temp=temp->next;

    node * temp2 = temp->next;
    temp->next=NULL;

    free(temp2);
    return head;
}


node * delete_largest(node * head)
{
    node * temp = head;
    node * temp2 = head;
    while (temp->next!=NULL)
     {
         if (temp->data>temp2->data)
            temp2=temp;

        temp=temp->next;
     }

     if (temp2->data==head->data)
        head=delete_from_front(head);
     else
        {
            temp=head;
            while (temp->next->data!=temp2->data)
                temp=temp->next;

            temp->next=temp->next->next;
            free(temp2);
        }

     return head;
}


node * delete_smallest(node * head)
{
    node * temp=head;
    node * temp2 = head;
     while (temp->next!=NULL)
     {
         if (temp->data<temp2->data)
            temp2=temp;

        temp=temp->next;
     }

     if (temp2->data==head->data)
        head=delete_from_front(head);

     else
        {
             temp=head;
            while (temp->next->data!=temp2->data)
                temp=temp->next;

            temp->next=temp->next->next;
            free(temp2);
        }

     return head;
}


void display(node * head)
{
    node * temp=head;
    printf ("\nThe current list is : \n");
    while (temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
}


int main(void)
{
    printf ("Hello, Welcome to the database.\n");
    int a=1;
    node * head=NULL;
    while (a!=8)
    {
        printf("\nMENU : \n");
        printf ("1.Insert at front.\n2.Insert at end.\n3.Delete from front.\n4.Delete from end.\n5.Delete largest.\n6.Delete smallest.\n7.Display.\n8.Exit menu.\n\n");
        scanf ("%d",&a);
        printf("\n");

        switch (a)
        {

        case 1 :
            {
                head=insert_at_front(head);
                display(head);
                break;
            }


        case 2 :
            {
                head=insert_at_end(head);
                display(head);
                break;
            }


        case 3 :
            {
                if (head==NULL)
                printf ("The list is empty, insert some values first.\n");
                else
                head=delete_from_front(head);
                display(head);
                break;
            }


        case 4 :
            {
                if (head==NULL)
                printf ("The list is empty, insert some values first.\n");
                else
                head=delete_from_end(head);
                display(head);
                break;
            }

        case 5 :
            {
                if (head==NULL)
                printf ("The list is empty, insert some values first.\n");
                else
                head=delete_largest(head);
                display(head);
                break;
            }
  	

        case 6 :
            {
                if (head==NULL)
                printf ("The list is empty, insert some values first.\n");
                else
                head=delete_smallest(head);
                display(head);
                break;
            }


        case 7 :
            {   if (head==NULL)
                printf ("The list is empty, insert some values first.\n");
                else
                display(head);
                break;
            }


        case 8 :
            {
                break;
            }


        default : printf ("Please enter a valid option.\n\n");
        }
   }
    printf ("Closing Database.\nThank You.\nCreated by - Mohit Kishore.\n");

    return 0;
}
