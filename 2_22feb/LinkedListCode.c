#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
// Each node contains two parts:
// 1. data: stores the actual value
// 2. next: pointer to the next node (means stores the address of the next node)
struct Node
{
    int data;
    struct Node *next;
};

// Global head pointer to keep track of the first node means for this code there was only one linked list so we are using head pointer to keep track of the first node and so for the linked elements
struct Node *head = NULL;

// Function to create a new node
// Returns: pointer to the newly created node
struct Node *NewNode(int data)
{
    // Allocate memory for new node using malloc please keep in mind about the syntax of malloc function and how it works
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1); // here exit(1) is used to terminate the program means if memory allocation fails then the program will be terminated
    }

    // Initialize the node's data and next pointer
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Function to insert at the beginning of list
// Time Complexity: O(1)
void insertAtBeginning(int data)
{
    // Create a new node
    struct Node *newNode = NewNode(data);

    // Make new node point to current head
    newNode->next = head;

    // Update head to point to new node
    head = newNode;
}

// Function to insert at the end of list
// Time Complexity: O(n) where n is the number of nodes
void insertAtEnd(int data)
{
    // Create a new node
    struct Node *newNode = NewNode(data);

    // If list is empty, make new node the head
    if (head == NULL)
    {
        head = newNode;
        return; // the meaning of return here is to terminate the function keep in mind about the difference between exit(1) and return as return terminates the function and exit(1) terminates the program.
    }

    // Traverse to the last node with help of a dummy pointer/node created in this funciton.
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Link new node after the last node, i hope you got the value of pointer concept here!!
    temp->next = newNode;
}

// Function to insert after a given position
// Time Complexity: O(n)
void insertAfterPos(int data, int position)
{
    // Create a new node
    struct Node *newNode = NewNode(data);
    if (position < 0)
    {
        printf("You dumb fucker how can you do it??, can position value can be negative!!!\n");
    }

    // If list is empty and position is not 0, return
    if (head == NULL && position > 0)
    {
        printf("List is empty! So cannot insert at position %d\n", position);
        free(newNode);
        return;
    }

    // If position is 0, insert at beginning
    if (position == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Traverse to the position
    struct Node *temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    // Check if position exists
    if (temp == NULL)
    {
        printf("Position %d not found!\n", position);
        free(newNode);
        return;
    }

    // Insert new node after the position
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete from beginning
// Time Complexity: O(1)
void deleteFromBeginning()
{
    // Check if list is empty
    if (head == NULL)
    {
        printf("List is empty! Nothing to delete\n");
        return;
    }

    // Save reference to head
    struct Node *temp = head;

    // Move head to next node
    head = head->next;

    // Free the memory of deleted node
    free(temp);
}

// Function to delete from end
// Time Complexity: O(n)
void deleteFromEnd()
{ // The basic and important thing is to consider all the cases of deletion from the linked list like if the list is empty, if the list has only one element, if the list has more than one element and we will be able to solve the question easily!!
    // Check if list is empty
    if (head == NULL)
    {
        printf("List is empty! Nothing to delete\n");
        return;
    }

    // If only one node exists
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    // Traverse to second last node
    struct Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    // Delete last node
    free(temp->next);
    temp->next = NULL;
}

// Function to search for an element
// Time Complexity: O(n)
int search(int key)
{
    struct Node *temp = head;
    int position = 0;

    // Traverse through the list
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return position; // Element found || one more important thing to keep in mind that when return is used in a function then the function is terminated so the next lines of code will not be executed. so as "return -1" tooo...
        }
        temp = temp->next;
        position++;
    }

    return -1; // Element not found
}

// Function to display the list
// Time Complexity: O(n)
void display()
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    printf("List elements: ");
    printf("[ ");
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != NULL)
        {
            printf(" -> ");
        }
    }
    printf(" ]\n");
}

// Function to free the entire list
// Time Complexity: O(n)
void freeList()
{
    struct Node *temp;

    // Delete nodes one by one
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function to demonstrate usage
int main()
{
    // Insert elements at beginning
    insertAtBeginning(30);
    insertAtBeginning(20);
    insertAtBeginning(10);

    printf("After inserting 10, 20, 30 at beginning:\n");
    display();

    // Insert elements at end
    insertAtEnd(40);
    insertAtEnd(50);

    printf("\nAfter inserting 40, 50 at end:\n");
    display();

    // Insert after position
    insertAfterPos(25, 2);

    printf("\nAfter inserting 25 at position 2:\n");
    display();

    // Delete from beginning
    deleteFromBeginning();

    printf("\nAfter deleting from beginning:\n");
    display();

    // Delete from end
    deleteFromEnd();

    printf("\nAfter deleting from end:\n");
    display();

    // Search for element
    printf("\nThe final representation of linked list after all the above changes is \n");
    display();

    int data;
    printf("\nEnter the element you want to search in the linked list\n");
    scanf("%d", &data);
    printf("\nElement 25 found at index : %d\n", search(data));

    // Free the list
    freeList();

    return 0;
}