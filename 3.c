/*Raj is looking for help with a circular linked list challenge! Design a program that
creates a circular linked list, then prompts the user to enter a new node&#39;s value and
the position where it should be inserted. After inserting the new node, display the
updated circular linked list to show the changes.
Input Format
The first line of input consists of an integer N, representing the number of elements
in the circular linked list.
The second line consists of N space-separated list of elements.
The third line consists of an integer, representing the value of the element to be
inserted.
The fourth line consists of an integer M, the position at which the element is to be
inserted (position starts from 1).
Output Format
The output prints N+1 space-separated integers representing the updated circular
linked list.
Constraints
In this scenario, the test cases fall under the following constraints:
2 ≤ N ≤ 10
0 ≤ elements ≤ 1000
2 ≤ M ≤ N
Sample Input Sample Output
3
13 25 37 13 59 25 37
59
2
Sample Input Sample Output
6
1 4 5 6 3 2 1 4 5 6 3 7 2
7
6
Time Limit: - ms Memory Limit: - kb Code Size: - kb*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
   int data;
   struct node *next;
};
struct node *head=NULL;

void insertEnd(int x)
{
   struct node *newnode,*temp;
   newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=x;
   if(head==NULL)
   {
       head=newnode;
       newnode->next=head;
   }
   else
   {
       temp=head;
       while(temp->next!=head)
           temp=temp->next;
       temp->next=newnode;
       newnode->next=head;
   }
}

void insertPosition(int val,int pos)
{
   struct node *newnode,*temp=head;
   int i;
   newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=val;
   for(i=1;i<pos-1;i++)
       temp=temp->next;
   newnode->next=temp->next;
   temp->next=newnode;
}

void display()
{
   struct node *temp=head;
   do
   {
       printf("%d ",temp->data);
       temp=temp->next;
   }while(temp!=head);
}

int main()
{
   int n,x,i,val,pos;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       scanf("%d",&x);
       insertEnd(x);
   }
   scanf("%d",&val);
   scanf("%d",&pos);
   insertPosition(val,pos);
   display();
   return 0;
}
