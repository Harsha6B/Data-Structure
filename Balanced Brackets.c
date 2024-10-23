#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define size 30
char stack[size];
int top=-1;
void push(char x)
{
    if(top == size-1)
    {
        printf("Stack is full!");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}
void pop()
{
    
    if(top==-1)
    {
        printf("Stack is empty!");
    }
    else
    {
        
        top--;
    }
}
char peek()
{
    if(top != -1)
    {
        return stack[top];
    }
    return '\0';
}
void main()
{
    char str[40];
    printf("Enter the expression:");
    scanf("%s",str);
    bool flag = true;
    for(int i=0; i<strlen(str); i++)
    {
        char ch = str[i];
        
        if(ch =='(' || ch == '[' || ch == '{')
        {
            push(ch);
        }
        else if(ch == ')' || ch == ']' || ch == '}')
        {
            if(top == -1)
            {
                flag = false;
                break;
            }
            else if(ch == ')' && peek() == '(')
            {
                pop();
            }
            else if(ch == ']' && peek() == '[')
            {
                pop();
            }
            else if(ch == '}' && peek() == '{')
            {
                pop();
            }
            else 
            {
                flag = false;
                break;
            }
        }
    }
    if(flag==true && top == -1)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
}

OUTPUT:
Enter the expression:{[(a+b)+{(c-d)*(e*f)}]}
true
