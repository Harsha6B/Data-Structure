#include<stdio.h>
#include<stdlib.h>
#define size 5
int dequeue[size];
int front=-1;
int rear=-1;
void enqueuefront(int x);
void enqueuerear(int x);
void dequeuefront();
void dequeuerear();
void display();
void getfront();
void getrear();
void main()
{
    int item,ch;
    while(1)
    {
        printf("\n1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Display\n");
        printf("6. getFront\n");
        printf("7. getRear\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter value to be inserted at front: ");
                    scanf("%d",&item);
                    enqueuefront(item);
                    break;
            case 2: printf("Enter value to be inserted at Rear: ");
                    scanf("%d",&item);
                    enqueuerear(item);
                    break;
            case 3: dequeuefront();
                    break;
            case 4: dequeuerear();
                    break;
            case 5: display();
                    break;
            case 6: getfront();
                    break;
            case 7: getrear();
                    break;
            default: printf("Invalid choice!");
                    break;
        }
    }
}
void enqueuefront(int item)
{
    if((front==0 && rear==size-1) || front == rear+1)
    {
        printf("Dequeue is full!");
    }
    else if(front == -1 && rear == -1)
    {
        front=rear=0;
        dequeue[front] = item;
    }
    else if(front == 0)
    {
        front = size -1;
        dequeue[front] = item;
    }
    else
    {
        front--;
        dequeue[front] = item;
    }
}
void enqueuerear(int item)
{
    if((front==0 && rear==size-1) || front == rear+1)
    {
        printf("Dequeue is full!");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        dequeue[rear] = item;
    }
    else if(rear == size -1)
    {
        rear = 0;
        dequeue[rear] = item;
    }
    else
    {
        rear++;
        dequeue[rear] = item;
    }
}
void dequeuefront()
{
    if(front == -1 && rear == -1)
    {
        printf("Dequeue is Empty!");
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else if(front == size-1)
    {
        printf("Dequeued element from front is: ");
        printf("%d",dequeue[front]);
        front = 0;
    }
    else
    {
        printf("Dequeued element from front is: ");

        printf("%d",dequeue[front]);
        front++;
    }
}
void dequeuerear()
{
    if(front == -1 && rear == -1)
    {
        printf("Dequeue is Empty!");
    }
    else if(front == rear)
    {
        printf("Dequeued element from rear is: ");
        printf("%d",dequeue[rear]);
        front = rear = -1;

    }
    else if(rear == 0)
    {
        printf("Dequeued element from rear is: ");
        printf("%d",dequeue[rear]);
        rear = size-1;
    }
    else
    {
        printf("Dequeued element from rear is: ");

        printf("%d",dequeue[rear]);
        rear--;
    }
}
void display()
{
    int i = front;
    if(front == -1 && rear == -1)
    {
        printf("Dequeue is Empty!");
    }
    else
    {

        printf("Displayed elements are:\n");
        while(i!=rear)
        {
            printf("%d\n",dequeue[i]);
            i = (i+1)%size;
        }
        printf("%d",dequeue[rear]);
    }
}
void getfront()
{
    if(front == -1 && rear == -1)
    {
        printf("Dequeue is Empty!");
    }
    else
    {
        printf("%d",dequeue[front]);
    }
}
void getrear()
{
    if(front == -1 && rear == -1)
    {
        printf("Dequeue is Empty!");
    }
    else
    {
        printf("%d",dequeue[rear]);
    }
}


OUTPUT:
1. Enqueue Front
2. Enqueue Rear
3. Dequeue Front
4. Dequeue Rear
5. Display
6. getFront
7. getRear
Enter your choice: 1
Enter value to be inserted at front: 1

1. Enqueue Front
2. Enqueue Rear
3. Dequeue Front
4. Dequeue Rear
5. Display
6. getFront
7. getRear
Enter your choice: 1
Enter value to be inserted at front: 2

1. Enqueue Front
2. Enqueue Rear
3. Dequeue Front
4. Dequeue Rear
5. Display
6. getFront
7. getRear
Enter your choice: 1
Enter value to be inserted at front: 3

1. Enqueue Front
2. Enqueue Rear
3. Dequeue Front
4. Dequeue Rear
5. Display
6. getFront
7. getRear
Enter your choice: 2
Enter value to be inserted at Rear: 4

1. Enqueue Front
2. Enqueue Rear
3. Dequeue Front
4. Dequeue Rear
5. Display
6. getFront
7. getRear
Enter your choice: 2
Enter value to be inserted at Rear: 5

1. Enqueue Front
2. Enqueue Rear
3. Dequeue Front
4. Dequeue Rear
5. Display
6. getFront
7. getRear
Enter your choice: 5
Displayed elements are:
3
2
1
4
5
1. Enqueue Front
2. Enqueue Rear
3. Dequeue Front
4. Dequeue Rear
5. Display
6. getFront
7. getRear
Enter your choice: 3
Dequeued element from front is: 3
1. Enqueue Front
2. Enqueue Rear
3. Dequeue Front
4. Dequeue Rear
5. Display
6. getFront
7. getRear
Enter your choice: 3
Dequeued element from front is: 2
1. Enqueue Front
2. Enqueue Rear
3. Dequeue Front
4. Dequeue Rear
5. Display
6. getFront
7. getRear
Enter your choice: 4
Dequeued element from rear is: 5
1. Enqueue Front
2. Enqueue Rear
3. Dequeue Front
4. Dequeue Rear
5. Display
6. getFront
7. getRear
Enter your choice: 4
Dequeued element from rear is: 4
1. Enqueue Front
2. Enqueue Rear
3. Dequeue Front
4. Dequeue Rear
5. Display
6. getFront
7. getRear
Enter your choice: 5
Displayed elements are:
1
1. Enqueue Front
2. Enqueue Rear
3. Dequeue Front
4. Dequeue Rear
5. Display
6. getFront
7. getRear
Enter your choice:










