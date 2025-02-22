#include <iostream>
using namespace std;

/*
 * Linked List-based Stack Implementation
 *
 * Key Concepts:
 * - Uses dynamic memory allocation for each element
 * - Each element (node) contains data and a pointer to the next node
 * - Top of stack is the first node in the linked list
 *
 * Advantages over Array-based Implementation:
 * 1. Dynamic size - can grow and shrink during runtime
 * 2. No waste of memory (space is allocated as needed)
 * 3. No stack overflow unless memory is exhausted
 *
 * Disadvantages:
 * 1. Extra memory needed for storing node pointers
 * 2. Not cache-friendly due to non-contiguous memory
 */

// Node structure representing each element in the stack
struct Node
{
    int data;   // The actual data stored in the node
    Node *next; // Pointer to the next node in the stack

    // Constructor to initialize node with given value
    // next is automatically set to nullptr (prevents dangling pointers)
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedListStack
{
private:
    Node *top; // Pointer to the top node of the stack
    int size;  // Tracks number of elements in stack

public:
    /* Constructor: Initializes an empty stack
     * - top is set to nullptr (empty stack)
     * - size is set to 0
     * Time Complexity: O(1)
     */
    LinkedListStack() : top(nullptr), size(0) {}

    /* Destructor: Frees all allocated memory
     * - Iteratively removes all nodes when stack is destroyed
     * - Prevents memory leaks
     * Time Complexity: O(n) where n is number of nodes
     */
    ~LinkedListStack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    /* Check if stack is empty
     * Returns true if top is nullptr (no nodes in stack)
     * Time Complexity: O(1)
     */
    bool isEmpty()
    {
        return top == nullptr;
    }

    /* Get current size of stack
     * Returns number of elements currently in stack
     * Time Complexity: O(1)
     */
    int getSize()
    {
        return size;
    }

    /* Push Operation: Adds new element to top of stack
     * Time Complexity: O(1)
     *
     * Steps:
     * 1. Create new node with given value
     * 2. Set new node's next pointer to current top
     * 3. Update top to point to new node
     * 4. Increment size counter
     */
    void push(int value)
    {
        Node *newNode = new Node(value); // Create new node
        newNode->next = top;             // Link new node to current top
        top = newNode;                   // Make new node the top
        size++;                          // Increment size
        cout << value << " pushed to stack" << endl;
    }

    /* Pop Operation: Removes and returns top element
     * Time Complexity: O(1)
     *
     * Steps:
     * 1. Check for empty stack
     * 2. Store top node's data
     * 3. Update top to next node
     * 4. Delete old top node
     * 5. Decrement size
     */
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Cannot pop from empty stack" << endl;
            return -1;
        }

        Node *temp = top;       // Store current top
        int popped = top->data; // Get data to return
        top = top->next;        // Move top to next node
        delete temp;            // Free memory of old top
        size--;                 // Decrement size
        return popped;
    }

    /* Peek Operation: Returns top element without removing it
     * Time Complexity: O(1)
     *
     * Unlike pop(), this operation:
     * - Doesn't modify the stack
     * - Doesn't free any memory
     * - Doesn't change size
     */
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return top->data;
    }

    /* Display Operation: Shows all elements in stack
     * Time Complexity: O(n) where n is number of elements
     *
     * Traverses from top to bottom, showing all elements
     * Helpful for debugging and visualization
     */
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }

        cout << "Stack elements (top to bottom): ";
        Node *current = top;
        while (current != nullptr)
        {
            cout << current->data;
            current = current->next;
            if (current != nullptr)
                cout << " -> ";
        }
        cout << endl;
    }
};

/* Main function to demonstrate stack operations
 * Shows common use cases and proper handling of edge cases
 */
int main()
{
    LinkedListStack stack;

    // Demonstrate push operations
    cout << "Pushing elements:" << endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Show current state
    cout << "\nCurrent stack:" << endl;
    stack.display();

    // Show size
    cout << "Stack size: " << stack.getSize() << endl;

    // Demonstrate peek
    cout << "\nTop element (using peek): " << stack.peek() << endl;

    // Demonstrate pop operations
    cout << "\nPopping elements:" << endl;
    cout << "Popped: " << stack.pop() << endl;
    cout << "Popped: " << stack.pop() << endl;

    // Show final state
    cout << "\nFinal stack:" << endl;
    stack.display();

    // Demonstrate error handling
    cout << "\nTrying to pop from near-empty stack:" << endl;
    cout << "Popped: " << stack.pop() << endl; // Last element
    cout << "Popped: " << stack.pop() << endl; // Should show underflow error

    return 0;
}