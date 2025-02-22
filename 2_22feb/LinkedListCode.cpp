#include <iostream>
#include <cstdlib>

using namespace std;

// Structure for a node in the linked list
// Each node contains two parts:
// 1. data: stores the actual value
// 2. next: pointer to the next node (stores the address of the next node)
struct Node
{
    int data;
    Node *next;

    // Constructor for Node
    Node(int val) : data(val), next(nullptr) {}
};

// Global head pointer to keep track of the first node
// For this code, there's only one linked list, so we use head pointer to track the first node
Node *head = nullptr;

// Function to create a new node
// Returns: pointer to the newly created node
Node *NewNode(int data)
{
    // Use new instead of malloc for memory allocation in C++
    Node *newNode = new Node(data);

    // Check if memory allocation was successful
    if (newNode == nullptr)
    {
        cout << "Memory allocation failed!\n";
        exit(1); // Terminate the program if memory allocation fails
    }

    return newNode;
}

// Function to insert at the beginning of list
// Time Complexity: O(1)
void insertAtBeginning(int data)
{
    Node *newNode = NewNode(data);
    newNode->next = head;
    head = newNode;
}

// Function to insert at the end of list
// Time Complexity: O(n) where n is the number of nodes
void insertAtEnd(int data)
{
    Node *newNode = NewNode(data);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to insert after a given position
// Time Complexity: O(n)
void insertAfterPos(int data, int position)
{
    if (position < 0)
    {
        cout << "Invalid position. Position cannot be negative.\n";
        return;
    }

    Node *newNode = NewNode(data);

    if (head == nullptr && position > 0)
    {
        cout << "List is empty! Cannot insert at position " << position << "\n";
        delete newNode;
        return;
    }

    if (position == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    for (int i = 0; i < position - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Position " << position << " not found!\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete from beginning
// Time Complexity: O(1)
void deleteFromBeginning()
{
    if (head == nullptr)
    {
        cout << "List is empty! Nothing to delete\n";
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
}

// Function to delete from end
// Time Complexity: O(n)
void deleteFromEnd()
{
    if (head == nullptr)
    {
        cout << "List is empty! Nothing to delete\n";
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

// Function to search for an element
// Time Complexity: O(n)
int search(int key)
{
    Node *temp = head;
    int position = 0;

    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            return position;
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
    if (head == nullptr)
    {
        cout << "List is empty!\n";
        return;
    }

    Node *temp = head;
    cout << "List elements: ";
    cout << "[ ";
    while (temp != nullptr)
    {
        cout << temp->data;
        temp = temp->next;
        if (temp != nullptr)
        {
            cout << " -> ";
        }
    }
    cout << " ]\n";
}

// Function to free the entire list
// Time Complexity: O(n)
void freeList()
{
    Node *temp;

    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// Main function to demonstrate usage
int main()
{
    // Insert elements at beginning
    insertAtBeginning(30);
    insertAtBeginning(20);
    insertAtBeginning(10);

    cout << "After inserting 10, 20, 30 at beginning:\n";
    display();

    // Insert elements at end
    insertAtEnd(40);
    insertAtEnd(50);

    cout << "\nAfter inserting 40, 50 at end:\n";
    display();

    // Insert after position
    insertAfterPos(25, 2);

    cout << "\nAfter inserting 25 at position 2:\n";
    display();

    // Delete from beginning
    deleteFromBeginning();

    cout << "\nAfter deleting from beginning:\n";
    display();

    // Delete from end
    deleteFromEnd();

    cout << "\nAfter deleting from end:\n";
    display();

    // Search for element
    cout << "\nThe final representation of linked list after all the above changes is \n";
    display();

    int data;
    cout << "\nEnter the element you want to search in the linked list: ";
    cin >> data;
    cout << "\nElement " << data << " found at index: " << search(data) << "\n";

    // Free the list
    freeList();

    return 0;
}
