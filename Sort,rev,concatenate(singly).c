#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* createnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> next = NULL;
    return newnode;
}

struct node* insertend(struct node* head, int data)
{
    struct node* newnode = createnode(data);
    if(head == NULL)
    {
        return newnode;
    }
    struct node* temp = head;
    while(temp -> next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

void printlist(struct node* temp)
{
    while(temp!= NULL)
    {
        printf("%d  ",temp->data);
        temp = temp->next;
    }
}

struct node* sortinglist(struct node* head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }
    struct node* temp1 = head;
    while(temp1!=NULL)
    {
        struct node* temp2 = temp1->next;
        while(temp2!=NULL)
        {
            if(temp1->data > temp2->data)
            {
                int t = temp1->data;
                temp1->data = temp2->data;
                temp2->data = t;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return head;
}

struct node* reversinglist(struct node* head)
{
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

struct node* concatenationlist(struct node* head1 , struct node* head2)
{
    if(head1==NULL)
    {
        return head2;
    }
    struct node* temp = head1;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp -> next = head2;
    return head1;
}
int main()
{
    struct node* list1 = NULL;
    struct node* list2 = NULL;
    
    int n,m,value;
    printf("Enter the no.of elements in list1: ");
    scanf("%d",&n);
    printf("Enter the elements of list1:\n");
    for(int k=0; k<n ; k++)
    {
        scanf("%d",&value);
        list1 = insertend(list1,value);
    }
    
    printf("Enter the no.of elements in list2: ");
    scanf("%d",&m);
    printf("Enter the elements of list2:\n");
    for(int k=0; k<m ; k++)
    {
        scanf("%d",&value);
        list2 = insertend(list2,value);
    }
    
    printf("List1: ");
    printlist(list1);
    printf("\nList2: ");
    printlist(list2);
    
    list1 = sortinglist(list1);
    printf("\nSorted list1 is: ");
    printlist(list1);
    
    list2 = sortinglist(list2);
    printf("\nSorted list2 is: ");
    printlist(list2);
    
    list1 = reversinglist(list1);
    printf("\nReversed list1 is: ");
    printlist(list1);
    
    list2 = reversinglist(list2);
    printf("\nReversed list2 is: ");
    printlist(list2);
    
    struct node* concatenatedlist = concatenationlist(list1,list2);
    printf("\nConcatenated list is: ");
    printlist(concatenatedlist);
    
    return 0;
}


*****OUTPUT*****
Enter the no.of elements in list1: 3
Enter the elements of list1:
56
15
89
Enter the no.of elements in list2: 3
Enter the elements of list2:
48
96
16
List1: 56  15  89  
List2: 48  96  16  
Sorted list1 is: 15  56  89  
Sorted list2 is: 16  48  96  
Reversed list1 is: 89  56  15  
Reversed list2 is: 96  48  16  
Concatenated list is: 89  56  15  96  48  16  

