#include <iostream>
using namespace std;

/*
 * Array-based Stack Implementation
 *
 * Stack: A linear data structure that follows the LIFO (Last In First Out) principle
 * - Elements are added and removed from the same end (called the 'top')
 * - Similar to a stack of plates where you can only add or remove from the top
 *
 * Advantages of Array Implementation:
 * 1. Easy to implement
 * 2. Memory is saved as pointers are not involved
 * 3. Memory is contiguous, which can help with performance
 *
 * Limitations:
 * 1. Fixed size - cannot grow beyond initial capacity
 * 2. May waste memory if stack is not full
 */
class ArrayStack
{
private:
    int *arr;     // Dynamic array to store stack elements
    int capacity; // Maximum number of elements the stack can hold
    int top;      // Index of the topmost element (top = -1 means empty stack)

public:
    // Constructor: Initializes the stack with given size
    // Parameters:
    // - size: Maximum number of elements the stack can hold
    ArrayStack(int size)
    {
        capacity = size;
        arr = new int[capacity]; // Allocate memory for array
        top = -1;                // Initialize top as -1 to indicate empty stack
    }

    // Destructor: Frees the dynamically allocated memory
    // Called automatically when stack object goes out of scope
    ~ArrayStack()
    {
        delete[] arr;
    }

    // Check if stack is full
    // Returns true if top has reached the maximum index (capacity - 1)
    bool isFull()
    {
        return top == capacity - 1;
    }

    // Check if stack is empty
    // Returns true if top is -1 (initial state)
    bool isEmpty()
    {
        return top == -1;
    }

    /* Push Operation: Adds an element to the top of stack
     * Time Complexity: O(1) - constant time operation
     *
     * Steps:
     * 1. Check if stack is full
     * 2. If not full, increment top
     * 3. Add new element at top position
     */
    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value; // Increment top and add value in one step
        cout << value << " pushed to stack" << endl;
    }

    /* Pop Operation: Removes and returns the top element
     * Time Complexity: O(1) - constant time operation
     *
     * Steps:
     * 1. Check if stack is empty
     * 2. If not empty, return top element and decrement top
     */
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Cannot pop from empty stack" << endl;
            return -1; // Return sentinel value to indicate error
        }
        return arr[top--]; // Return current top value and then decrement top
    }

    /* Peek Operation: Returns the top element without removing it
     * Time Complexity: O(1) - constant time operation
     *
     * Unlike pop(), peek() doesn't modify the stack
     */
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    /* Display Operation: Shows all elements in the stack
     * Time Complexity: O(n) where n is the number of elements
     *
     * Prints elements from top to bottom
     * This is helpful for debugging and visualization
     */
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i];
            if (i > 0)
                cout << " -> ";
        }
        cout << endl;
    }

    // Get current size of stack
    // Returns number of elements currently in stack
    int getSize()
    {
        return top + 1;
    }
};

/* Main function demonstrating various stack operations
 * Shows common use cases and how to handle different scenarios
 */
int main()
{
    // Create a stack of size 5
    ArrayStack stack(5);

    // Demonstrate push operations
    cout << "Pushing elements to stack:" << endl;
    stack.push(10); // First element
    stack.push(20); // Second element
    stack.push(30); // Third element

    // Show current state
    cout << "\nCurrent stack state:" << endl;
    stack.display();

    // Demonstrate peek operation
    cout << "\nTop element (using peek): " << stack.peek() << endl;

    // Demonstrate pop operations
    cout << "\nPopping elements:" << endl;
    cout << "Popped: " << stack.pop() << endl;
    cout << "Popped: " << stack.pop() << endl;

    // Show final state
    cout << "\nFinal stack state:" << endl;
    stack.display();

    // Demonstrate stack size
    cout << "Current stack size: " << stack.getSize() << endl;

    // Demonstrate error handling
    cout << "\nTrying to pop from near-empty stack:" << endl;
    cout << "Popped: " << stack.pop() << endl; // Last element
    cout << "Popped: " << stack.pop() << endl; // Should show underflow error

    return 0;
}