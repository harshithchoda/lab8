/*Saran is tasked with implementing a doubly linked list in data structures, allowing
users to append elements to the end of the list, and remove the last element. He
needs to ensure efficient memory management in the implementation.
Assist him with a suitable program.
Input Format
The first line of input consists of an integer n, representing the size of the list.
The second line consists of n space-separated integers, representing the elements
of the list.
Output Format
The output displays integers, representing the list after removing the last element,
separated by a space.
Refer to the sample output for formatting specifications.
Constraints
The given test cases fall under the following constraints:
1 ≤ n ≤ 30
1 ≤ elements of the list ≤ 100
Sample Input Sample Output
5 48 22 5 62
48 22 5 62 87
Sample Input Sample Output
7 65 20 87 61 44 67
65 20 87 61 44 67 31

Time Limit: - ms Memory Limit: - kb Code Size: - kb*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
   int data;
   struct node *prev;
   struct node *next;
};
struct node *head=NULL;

void insertEnd(int x)
{
   struct node *newnode,*temp;
   newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=x;
   newnode->next=NULL;
   if(head==NULL)
   {
       newnode->prev=NULL;
       head=newnode;
   }
   else
   {
       temp=head;
       while(temp->next!=NULL)
           temp=temp->next;
       temp->next=newnode;
       newnode->prev=temp;
   }
}

void deleteLast()
{
   struct node *temp=head;
   while(temp->next!=NULL)
       temp=temp->next;
   if(temp->prev!=NULL)
       temp->prev->next=NULL;
   else
       head=NULL;
   free(temp);
}

void display()
{
   struct node *temp=head;
   while(temp!=NULL)
   {
       printf("%d ",temp->data);
       temp=temp->next;
   }
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

