#include<stdio.h>
#include<stdlib.h>
#define size 5
int front=-1;
int rear=-1;
int queue[size];
void enqueue(int);
void dequeue();
void display();
void peek();
void main()
{
    int item,ch;
    while(1)
    {
        printf("\n1.Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the value to be inserted: ");
                    scanf("%d",&item);
                    enqueue(item);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: peek();
                    break;
            case 5: exit(0);
                    break;
            default: printf("Invalid choice!");
                    break;
        }
    }
}
void enqueue(int item)
{
    if(rear==size-1){
        printf("Queue is full!");
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=item;
    }
    else{
        rear=rear+1;
        queue[rear]=item;
    }
}
void dequeue()
{
    if(front==-1 && rear==-1){
        printf("Queue is empty!");
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        front++;
        printf("%d",queue[front]);
    }
}
void display()
{
    if(front==-1 && rear==-1){
        printf("Queue is empty!");
    }
    else{
        int i;
        printf("Queue elements are: \n");
        for(i=front; i<=rear; i++){
            printf("%d\n",queue[i]);
        }
    }
}
void peek()
{
   if(front==-1 && rear==-1){
        printf("Queue is empty!");
    } 
    else{
        printf("%d",queue[front]);
    }
}
