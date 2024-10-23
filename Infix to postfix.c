#include<stdio.h>
#include<string.h>
#define size 30
char st1[size];
char st2[size];
int t1=-1;
int t2=-1;

int precedence(char ch)
{
    if(ch == '+' || ch == '-')
    {
        return 1;
    }
    else if(ch== '*' || ch == '/')
    {
        return 2;
    }
    return 0;
}
void push1(char x)
{
    if(t1 == size-1)
    {
        printf("Stack is full\n");
        return;
    }
    else
    {
        t1++;
        st1[t1] = x;
    }
}
void push2(char x)
{
    if(t2 == size-1)
    {
        printf("Stack is full\n");
        return;
    }
    else
    {
        t2++;
        st2[t2] = x;
    }
}
char pop1()
{
    if(t1 == -1)
    {
        printf("Stack is empty!");
        return '\0';
    }
    return st1[t1--];
}
char pop2()
{
    if(t2 == -1)
    {
        printf("Stack is empty!");
        return '\0';
    }
    return st2[t2--];
}
char peek2()
{
    if(t2 != -1)
    {
        return st2[t2];
    }
    return '\0';
}
void main()
{
    char exp[40];
    printf("Enter the expression:");
    scanf("%s",exp);
    for(int i=0; i<strlen(exp); i++)
    {
        char ch = exp[i];
        if(ch == '(')
        {
            push2(ch);
        }
        else if(ch == ')')
        {
            while(peek2() != '(')
            {
                push1(pop2());
            }
            pop2();
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch =='/')
        {
            while(t2>-1 && precedence(peek2()) >= precedence(ch))
            {
                push1(pop2());
            }
            push2(ch);
        }
        else if(ch>='a' && ch<='z')
        {
            push1(ch);
        }
    }
    while(t2>-1)
    {
        push1(pop2());
    }
    for(int i=0; i<=t1; i++)
    {
        printf("%c",st1[i]);
    }

}

OUTPUT:
Enter the expression:a*(b-c+d)/e
abc-d+*e/
Process returned 8 (0x8)   execution time : 17.505 s
Press any key to continue.
