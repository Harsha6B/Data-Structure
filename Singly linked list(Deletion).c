#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void deleteatbeginning(struct node* *head)
{
    if(*head == 0)
    {
        return;
    }
    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteatend(struct node* *head)
{
    if(*head == 0)
    {
        return;
    }
    if((*head) -> next ==0)
    {
        free(*head);
        *head = 0;
        return;
    }
    struct node* temp = *head;
    struct node* prev = 0;
    
    while(temp->next != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    prev -> next = 0;
    free(temp);
}

void deleteatposition(struct node* *head, int position)
{
    if(*head == 0)
    {
        return;
    }
    if(position == -1)
    {
        deleteatbeginning(head);
        return;
    }
    struct node* temp = *head;
    struct node* prev = 0;
    int count = 1;
    
    while(temp!=0 && count<position)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }
    if(temp == 0)
    {
        return;
    }
    prev->next = temp->next;
    free(temp);
}
void listelements(struct node* head)
{
    struct node* temp = head;
    while(temp != 0)
    {
        printf("%d\n" , temp->data);
        temp = temp->next;
    }
}
int main()
{
    struct node* head = NULL;
    struct node* temp;
    int data;
    int choice;
    int position;
    
    printf("Enter numbers to add to the list(Enter -1 to stop): \n");
    while(1)
    {
        scanf("%d",&data);
        if(data == -1)
        {
            break; 
        }
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode -> data = data;
        newnode -> next = NULL;
        
        if(head == NULL)
        {
            head = newnode;
        }
        else{
            temp -> next = newnode;
        }
        temp = newnode;
    }
    printf("Initial list:\n");
    listelements(head);
    
    while(1)
    {
        printf("\n1. Delete at the beginning\n");
        printf("2. Delete at the end\n");
        printf("3. Delete at the specific position\n");
        printf("4. List elements\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: deleteatbeginning(&head);
                    break;
            case 2: deleteatend(&head);
                    break;
            case 3: printf("Enter position to delete: ");
                    scanf("%d",&position);
                    deleteatposition(&head,position);
                    break;
            case 4: listelements(head);
                    continue;
            case 5: return 0;
            default: printf("Invalid choice! \n");
                     continue;
        }
        printf("Updated list:\n");
        listelements(head);
    }
    return 0;
}


*****OUTPUT:*****

Enter numbers to add to the list(Enter -1 to stop): 
10
20
30
40
50
-1
Initial list:
10
20
30
40
50

1. Delete at the beginning
2. Delete at the end
3. Delete at the specific position
4. List elements
5. Exit
Enter your choice: 1
Updated list:
20
30
40
50

1. Delete at the beginning
2. Delete at the end
3. Delete at the specific position
4. List elements
5. Exit
Enter your choice: 2
Updated list:
20
30
40

1. Delete at the beginning
2. Delete at the end
3. Delete at the specific position
4. List elements
5. Exit
Enter your choice: 3
Enter position to delete: 2
Updated list:
20
40

1. Delete at the beginning
2. Delete at the end
3. Delete at the specific position
4. List elements
5. Exit
Enter your choice: 4
20
40

1. Delete at the beginning
2. Delete at the end
3. Delete at the specific position
4. List elements
5. Exit
Enter your choice: 5


=== Code Execution Successful ===
