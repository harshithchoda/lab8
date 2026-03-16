/*Bob is tasked with developing a company&#39;s employee record management system.
The system needs to maintain a list of employee records using a doubly linked list.
Each employee is represented by a unique integer ID.
Help Bob to complete a program that adds employee records at the front, traverses
the list, and prints the same for each addition of employees to the list.
Input Format
The first line of input consists of an integer N, representing the number of
employees.
The second line consists of N space-separated integers, representing the employee
IDs.
Output Format
For each employee ID, the program prints &quot;Node Inserted&quot; followed by the current
state of the doubly linked list, with the data values of each node separated by
spaces.
Refer to the sample output for formatting specifications.
Constraints
1 ≤ N ≤ 15
1 ≤ employee ID ≤ 10 5
Sample Input Sample Output
4 Node Inserted
101 102 103 104 101
Node Inserted
102 101
Node Inserted
103 102 101
Node Inserted
104 103 102 101
Sample Input Sample Output
5 Node Inserted 201
201 202 203 204 205 Node Inserted 202 201
Node Inserted 203 202 201
Node Inserted 204 203 202 201
Node Inserted 205 204 203 202
201
Time Limit: - ms Memory Limit: - kb Code Size: - kb*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
   int data;
   struct node *prev;
   struct node *next;
};
struct node *head = NULL;

void insertFront(int x)
{
   struct node *newnode;
   newnode = (struct node*)malloc(sizeof(struct node));
   newnode->data = x;
   newnode->prev = NULL;
   newnode->next = head;
   if(head != NULL)
       head->prev = newnode;
   head = newnode;
   printf("Node Inserted\n");
   struct node *temp = head;
   while(temp != NULL)
   {
       printf("%d ", temp->data);
       temp = temp->next;
   }
   printf("\n");
}

int main()
{
   int n,x,i;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       scanf("%d",&x);
       insertFront(x);
   }
   return 0;
}

