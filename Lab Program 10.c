#include <stdio.h> 
#include <stdlib.h> 
 
#define MAX_EMPLOYEES 100 // Maximum number of employees 
#define MAX_KEYS 100      // Maximum number of keys 
#define TABLE_SIZE 10     // Size of hash table (m) 
 
typedef struct { 
    int key; 
    // You can add other employee details here 
    // For simplicity, we use just the key 
} Employee; 
 
int hashTable[TABLE_SIZE]; // Hash table to store keys 
  
Employee employees[MAX_EMPLOYEES]; // Array to store employee records 
int N; // Number of employees 
int m = TABLE_SIZE; // Size of the hash table 
 
// Hash function: H(K) = K mod m 
int hashFunction(int key) { 
    return key % m; 
} 
 
// Linear Probing to resolve collisions 
int linearProbing(int key) { 
    int index = hashFunction(key); 
    int originalIndex = index; // Store original index to detect full table 
     
    while (hashTable[index] != -1) { 
        if (hashTable[index] == key) { 
            return index; // Key already exists (no insertion needed) 
        } 
        // Linear probing: move to the next index 
        index = (index + 1) % m; 
         
        // If we have checked all positions, return -1 indicating table is full 
        if (index == originalIndex) { 
            return -1; 
        } 
    } 
    return index; 
} 
 
// Function to insert a key into the hash table 
void insert(int key) { 
    int index = linearProbing(key); 
     
    if (index != -1) { 
        hashTable[index] = key; // Store the key at the found index 
        printf("Key %d inserted at index %d\n", key, index); 
    } else { 
        printf("Error: Hash table is full. Key %d cannot be inserted.\n", key); 
    } 
} 
 
// Function to display the hash table 
void displayHashTable() { 
    printf("\nHash Table:\n"); 
    for (int i = 0; i < m; i++) { 
        if (hashTable[i] != -1) { 
            printf("Index %d: Key %d\n", i, hashTable[i]); 
        } else { 
            printf("Index %d: Empty\n", i); 
        } 
  
    } 
} 
 
int main() { 
    // Initialize hash table to -1 (empty) 
    for (int i = 0; i < m; i++) { 
        hashTable[i] = -1; 
    } 
 
    printf("Enter number of employees: "); 
    scanf("%d", &N); 
 
    printf("Enter the employee keys (4-digit numbers):\n"); 
    for (int i = 0; i < N; i++) { 
        scanf("%d", &employees[i].key); // Read key for each employee 
    } 
 
    // Insert the employee keys into the hash table 
    for (int i = 0; i < N; i++) { 
        insert(employees[i].key); 
    } 
 
    // Display the final hash table 
    displayHashTable(); 
 
    return 0; 
}

Output

Enter number of employees: 5

Enter the employee keys (4-digit numbers):

1234 5678 9012 3456 7890

Key 14 inserted at index 4

Key 5678 inserted at index 8

Key 9012 inserted at index 2

Key 3456 inserted at index 6

Key 7890 inserted at index 0

Hash Table:

Index 0:

Key 7890

Index 1: Empty

Index 2:

Key 9012

Index 3:

Empty

Index 4:

Key 1234

Index 5:

Empty

Index 6:

Key 3456

Index 7:

Empty

Index 8:

Key 5678

Index 9:

Empty

Code Execution Successful
