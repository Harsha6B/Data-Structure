#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node *prev;
struct Node *next;
};
struct Node* createNode(int data) {
struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
if (!newNode) {
printf("Memory allocation failed\n");
exit(1);
}
newNode->data = data;
newNode->prev = NULL;
newNode->next = NULL;
return newNode;
}
void insertLeft(struct Node **head, struct Node *node, int data) {
struct Node *newNode = createNode(data);
newNode->next = node;
newNode->prev = node->prev;
if (node->prev != NULL) {
node->prev->next = newNode;
} else {
*head = newNode;
}
node->prev = newNode;
}
void deleteNode(struct Node **head, int value) {
struct Node *temp = *head;
while (temp != NULL && temp->data != value) {
temp = temp->next;
}
if (temp == NULL) {
printf("Node with value %d not found\n", value);
return;
}
32
if (temp->prev != NULL) {
temp->prev->next = temp->next;
} else {
*head = temp->next;
}
if (temp->next != NULL) {
temp->next->prev = temp->prev;
}
free(temp);
}
void displayList(struct Node *head) {
struct Node *temp = head;
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}
int main() {
struct Node *head = NULL;
struct Node *node1, *node2, *node3;
int choice, data, value;
while (1) {
printf("\nMenu:\n");
printf("1. Create initial list\n");
printf("2. Insert a new node to the left of a node\n");
printf("3. Delete a node based on a specific value\n");
printf("4. Display the contents of the list\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:node1 = createNode(1);
node2 = createNode(2);
node3 = createNode(3);
head = node1;
node1->next = node2;
node2->prev = node1;
node2->next = node3;
node3->prev = node2;
printf("Initial list created with nodes 1, 2, 3\n");
break;
case 2:printf("Enter the value of the node to the left of which you want to insert: ");
scanf("%d", &value);
printf("Enter the data to insert: ");
33
scanf("%d", &data);
struct Node *temp = head;
while (temp != NULL && temp->data != value) {
temp = temp->next;
}
if (temp != NULL) {
insertLeft(&head, temp, data);
printf("Inserted %d to the left of %d\n", data, value);
} else {
printf("Node with value %d not found\n", value);
}
break;
case 3:
printf("Enter the value of the node to delete: ");
scanf("%d", &value);
deleteNode(&head, value);
break;
case 4:
displayList(head);
break;
case 5:
exit(0);
break;
default:
printf("Invalid choice\n");
break;
}
}
return 0;
}


*****OUTPUT*****
Menu:
1. Create initial list
2. Insert a new node to the left of a node
3. Delete a node based on a specific value
4. Display the contents of the list
5. Exit
Enter your choice: 1
Initial list created with nodes 1, 2, 3

Menu:
1. Create initial list
2. Insert a new node to the left of a node
3. Delete a node based on a specific value
4. Display the contents of the list
5. Exit
Enter your choice: 2
Enter the value of the node to the left of which you want to insert: 2
Enter the data to insert: 10
Inserted 10 to the left of 2

Menu:
1. Create initial list
2. Insert a new node to the left of a node
3. Delete a node based on a specific value
4. Display the contents of the list
5. Exit
Enter your choice: 4
1 10 2 3 

Menu:
1. Create initial list
2. Insert a new node to the left of a node
3. Delete a node based on a specific value
4. Display the contents of the list
5. Exit
Enter your choice: 3
Enter the value of the node to delete: 3

Menu:
1. Create initial list
2. Insert a new node to the left of a node
3. Delete a node based on a specific value
4. Display the contents of the list
5. Exit
Enter your choice: 4
1 10 2 

Menu:
1. Create initial list
2. Insert a new node to the left of a node
3. Delete a node based on a specific value
4. Display the contents of the list
5. Exit
Enter your choice: 5


=== Code Execution Successful ===
