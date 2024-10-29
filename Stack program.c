#include<stdio.h>
#include<stdlib.h>
#define size 3
int stack[size];
int top=-1;
void push(int);
void pop();
void display();
void peek();
void main()
{
    int ch,item;
    while(1)
    {
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Peek");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the value to be inserted: ");
                    scanf("%d",&item);
                    push(item);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: peek();
                    break;
            case 5: exit(0);
                    break;
            default: printf("inavlid choice!");
                    break;
        }
    }
}
void push(int item)
{
    if(top==size-1){
        printf("OVERFLOW");
    }
    else{
        top++;
        stack[top]=item;
        printf("Insertion success");
    }
}
void pop()
{
    int item;
    if(top==-1){
        printf("UNDERFLOW");
    }
    else{
        item = stack[top--];
        printf("deleted");
    }
}
void display()
{
    if(top==-1){
        printf("UNDERFLOW");
    }
    else{
        int i;
        printf("Stack elements are:\n");
        for(i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}
void peek()
{
    if(top==-1){
        printf("UNDERFLOW");
    }
    else
    {
        printf("%d",stack[top]);
    }
}


OUTPUT:
1.Push
2.Pop
3.Display
4.Peek5.Exit
Enter your choice: 1
Enter the value to be inserted: 10
Insertion success
1.Push
2.Pop
3.Display
4.Peek5.Exit
Enter your choice: 1
Enter the value to be inserted: 20
Insertion success
1.Push
2.Pop
3.Display
4.Peek5.Exit
Enter your choice: 1
Enter the value to be inserted: 30
Insertion success
1.Push
2.Pop
3.Display
4.Peek5.Exit
Enter your choice: 1
Enter the value to be inserted: 40
OVERFLOW
1.Push
2.Pop
3.Display
4.Peek5.Exit
Enter your choice: 3
Stack elements are:
30
20
10

1.Push
2.Pop
3.Display
4.Peek5.Exit
Enter your choice: 2
deleted
1.Push
2.Pop
3.Display
4.Peek5.Exit
Enter your choice: 3
Stack elements are:
20
10

1.Push
2.Pop
3.Display
4.Peek5.Exit
Enter your choice: 4
20
1.Push
2.Pop
3.Display
4.Peek5.Exit
Enter your choice: 2
deleted
1.Push
2.Pop
3.Display
4.Peek5.Exit
Enter your choice: 2
deleted
1.Push
2.Pop
3.Display
4.Peek5.Exit
Enter your choice: 2
UNDERFLOW
1.Push
2.Pop
3.Display
4.Peek5.Exit
Enter your choice: 3
UNDERFLOW
1.Push
2.Pop
3.Display
4.Peek5.Exit
Enter your choice: 4
UNDERFLOW
1.Push
2.Pop
3.Display
4.Peek5.Exit
Enter your choice: 5
=== Code Execution Successful ===
