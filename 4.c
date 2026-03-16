/*In a coding challenge, participants are asked to create a program to handle a circular
linked list representing a queue at a supermarket.
The task is to develop a function to remove the last person from the queue where
each customer is identified by a unique identifier. Write a program for the same.
Input Format
The first line of input consists of an integer N, representing the number of persons in
the queue.
The second line consists of N space-separated integers representing the unique
identifiers of persons in the queue.
Output Format
The output prints the circular linked list after removing the last person.
Refer to the sample output for formatting specifications.
Constraints
In this scenario, the test cases fall under the following constraints:
1 ≤ N ≤ 30
1 ≤ unique identifier ≤ 1000
Sample Input Sample Output
7
12 59 23 70 71 34 78 12 59 23 70 71 34
Sample Input Sample Output
5 32 28 49 26
32 28 49 26 18
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

void deleteLast()
{
   struct node *temp=head,*prev;
   while(temp->next!=head)
   {
       prev=temp;
       temp=temp->next;
   }
   prev->next=head;
   free(temp);
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
   int n,x,i;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       scanf("%d",&x);
       insertEnd(x);
   }
   deleteLast();
   display();
   return 0;
}
