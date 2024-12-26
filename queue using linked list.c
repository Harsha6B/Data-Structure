#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *next;
};
void enqueue(struct Node* *front,struct Node* *rear,int data){
struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
newnode->data=data;
newnode->next=NULL;
if(*front==NULL && *rear==NULL){
*front=*rear=newnode;
}
else{
(*rear)->next=newnode;
*rear=newnode;
}
}
void dequeue(struct Node* *front,struct Node* *rear){
if(*front==NULL && *rear==NULL){
printf("Queue is empty\n");
}
else if(*front==*rear){
*front=*rear=NULL;
}
else{
*front=(*front)->next;
}
}
void display(struct Node* front){
struct Node *temp=front;
if(front==NULL){
printf("Queue is empty\n");
}
while(temp!=NULL){
printf("%d ",temp->data);
temp=temp->next;
}
printf("\n");
}
30
void main(){
int data,choice;
struct Node *front=NULL;
struct Node *rear=NULL;
while(1){
printf("1.Enqueue\n");
printf("2.Dequeue\n");
printf("3.Display\n");
printf("4.Exit\n");
printf("Enter your choice:");
scanf("%d",&choice);
switch(choice){
case 1:printf("Enter data:");
scanf("%d",&data);
enqueue(&front,&rear,data);
break;
case 2:dequeue(&front,&rear);
break;
case 3:display(front);
break;
case 4:exit(0);
break;
default:printf("Invalid choice\n");
}
}
}
