#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void insertatbeginning(struct node* *head,int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> next = *head;
    *head = newnode;
}

void insertatend(struct node* *head,int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> next = 0;
    
    if(*head == 0)
    {
        *head = newnode;
        return;
    }
    struct node* temp = *head;
    while(temp->next != 0)
    {
        temp = temp -> next;
    }
    temp -> next = newnode;
}

void insertatposition(struct node* *head,int data,int position)
{
    if(position == 0)
    {
        insertatbeginning(head,data);
        return;
    }
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    
    struct node* temp = *head;
    for(int i =0;i<position -1 && temp!=0; i++)
    {
        temp = temp->next;
    }
    if(temp == 0)
    {
        printf("position is out the list! \n");
        free(newnode);
        return;
    }
    newnode -> next = temp->next;
    temp -> next = newnode;
}

void listelements(struct node* head)
{
    struct node* temp = head;
    while (temp!= NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}


int main()
{
    struct node* head = 0;
    int choice;
    int data;
    int position;
    
    while(1)
    {
        printf("Choose an option:  ");
        printf("\n1. Insert at the beginning:\n");
        printf("2. Insert at the end:\n");
        printf("3. Insert at the specific position:\n");
        printf("4. List elements:\n");
        printf("5. Exit:\n");
        printf("Enter your choice:  ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the data to insert at the beginning:     ");
                    scanf("%d",&data);
                    insertatbeginning(&head,data);
                    break;
            case 2: printf("Enter the data to insert at the end: ");
                    scanf("%d",&data);
                    insertatend(&head,data);
                    break;
            case 3: printf("Enter the data to be inserted: ");
                    scanf("%d",&data);
                    printf("Enter the position where the data should be inserted: ");
                    scanf("%d",&position);
                    insertatposition(&head,data,position);
                    break;
            case 4: printf("The list elements are:\n");
                    listelements(head);
                    break;
            case 5: exit(0);
                    break;
            default:printf("Invalid choice:\n");
                    break;
        }
    }
}


****OUTPUT:*****

Choose an option:  
1. Insert at the beginning:
2. Insert at the end:
3. Insert at the specific position:
4. List elements:
5. Exit:
Enter your choice:  1
Enter the data to insert at the beginning:     10
Choose an option:  
1. Insert at the beginning:
2. Insert at the end:
3. Insert at the specific position:
4. List elements:
5. Exit:
Enter your choice:  2
Enter the data to insert at the end: 30
Choose an option:  
1. Insert at the beginning:
2. Insert at the end:
3. Insert at the specific position:
4. List elements:
5. Exit:
Enter your choice:  3
Enter the data to be inserted: 20
Enter the position where the data should be inserted: 1
Choose an option:  
1. Insert at the beginning:
2. Insert at the end:
3. Insert at the specific position:
4. List elements:
5. Exit:
Enter your choice:  4
The list elements are:
10
20
30
Choose an option:  
1. Insert at the beginning:
2. Insert at the end:
3. Insert at the specific position:
4. List elements:
5. Exit:
Enter your choice:  3
Enter the data to be inserted: 15
Enter the position where the data should be inserted: 5
position is out the list! 
Choose an option:  
1. Insert at the beginning:
2. Insert at the end:
3. Insert at the specific position:
4. List elements:
5. Exit:
Enter your choice:  6
Invalid choice:
Choose an option:  
1. Insert at the beginning:
2. Insert at the end:
3. Insert at the specific position:
4. List elements:
5. Exit:
Enter your choice:  4
The list elements are:
10
20
30
Choose an option:  
1. Insert at the beginning:
2. Insert at the end:
3. Insert at the specific position:
4. List elements:
5. Exit:
Enter your choice:  5


=== Code Execution Successful ===
