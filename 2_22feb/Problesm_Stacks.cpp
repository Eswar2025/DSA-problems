/*
    Medium Level Questions and Solutions for Stack Data Structure
    Practice these problems without help to better understand stack concepts.

    **Hint** Enter Alt + Z to wrap the code in Visual Studio Code.
*/

/*      Conceptual Questions:

1. Q: What is the fundamental difference between a stack and a queue?
   A: A stack follows LIFO (Last In First Out) principle where elements are added and removed
      from the same end, while a queue follows FIFO (First In First Out) where elements are
      added at one end and removed from the other.

2. Q: Why is stack called a recursive data structure?
   A: The structure of a stack naturally matches recursive function calls, where each new call
      is pushed onto the stack and each return pops from the stack. Also, many stack operations
      can be implemented recursively.

3. Q: What are the advantages and disadvantages of array-based vs linked list-based stack implementations?
   A: Array-based:
      Advantages: Better cache locality, less memory per element
      Disadvantages: Fixed size, may need resizing
      Linked list-based:
      Advantages: Dynamic size, no overflow unless memory exhausted
      Disadvantages: Extra memory for pointers, poor cache locality

4. Q: What is stack overflow and stack underflow?
   A: Stack overflow occurs when trying to push onto a full stack (in array implementation)
      Stack underflow occurs when trying to pop from an empty stack
      Both are error conditions that need to be handled appropriately

5. Q: Why are stacks useful in expression evaluation?
   A: Stacks help manage operator precedence and nested expressions naturally. They can hold
      operators or operands while waiting for higher precedence operations to complete.

6. Q: How does a stack help in implementing function calls in programming languages?
   A: The call stack stores function parameters, return addresses, and local variables.
      Each function call pushes a new frame, and each return pops the frame, maintaining
      proper function execution order.

7. Q: What is the role of stacks in backtracking algorithms?
   A: Stacks store the state of each choice point, allowing the algorithm to "backtrack"
      by popping states when a path doesn't lead to a solution.

8. Q: Why are stacks preferred over recursion in some cases?
   A: Stacks can prevent stack overflow in deep recursion, provide better control over
      memory usage, and can be more efficient as they avoid function call overhead.

9. Q: How does browser history implementation relate to stacks?
   A: Browser history uses two stacks: one for "back" history and one for "forward" history.
      Each new page pushes onto "back" stack, while using back button moves pages between stacks.

10. Q: What is the significance of top pointer in stack implementation?
    A: The top pointer keeps track of the most recently added element, enabling O(1) push and
       pop operations. It's crucial for maintaining the LIFO property of the stack.
*/

// Basic stack class using templates for flexibility
template <typename T>
class Stack
{
    vector<T> data;
    int topIndex;
    int capacity;

public:
    Stack(int size) : capacity(size), topIndex(-1)
    {
        data.reserve(capacity);
    }

    bool push(T value);
    T pop();
    T peek();
    bool isEmpty();
    bool isFull();
};

// Practice Problems:

// 1. Implement a stack that supports finding minimum element in O(1) time
class MinStack
{
private:
    stack<int> mainStack;
    stack<int> minStack; // Keeps track of minimum elements

public:
    void push(int val)
    {
        mainStack.push(val);
        if (minStack.empty() || val <= minStack.top())
        {
            minStack.push(val);
        }
    }

    void pop()
    {
        if (!mainStack.empty())
        {
            if (mainStack.top() == minStack.top())
            {
                minStack.pop();
            }
            mainStack.pop();
        }
    }

    int top()
    {
        return mainStack.empty() ? -1 : mainStack.top();
    }

    int getMin()
    {
        return minStack.empty() ? -1 : minStack.top();
    }
};

// 2. Function to evaluate postfix expression
int evaluatePostfix(string expr)
{
    stack<int> st;

    for (char c : expr)
    {
        if (isdigit(c))
        {
            st.push(c - '0');
        }
        else
        {
            int val2 = st.top();
            st.pop();
            int val1 = st.top();
            st.pop();

            switch (c)
            {
            case '+':
                st.push(val1 + val2);
                break;
            case '-':
                st.push(val1 - val2);
                break;
            case '*':
                st.push(val1 * val2);
                break;
            case '/':
                st.push(val1 / val2);
                break;
            }
        }
    }
    return st.top();
}

// 3. Convert infix expression to postfix
string infixToPostfix(string expr)
{
    stack<char> st;
    string result;
    map<char, int> precedence{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};

    for (char c : expr)
    {
        if (isalnum(c))
        {
            result += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop(); // Remove '('
        }
        else
        {
            while (!st.empty() && st.top() != '(' &&
                   precedence[c] <= precedence[st.top()])
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}

// 4. Implement a stack using queues
class StackUsingQueues
{
    queue<int> q1, q2;

public:
    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop()
    {
        if (q1.empty())
            return -1;
        int val = q1.front();
        q1.pop();
        return val;
    }
};

// 5. Function to check if an expression has balanced brackets
bool isBalanced(string expr)
{
    stack<char> st;
    map<char,char> brackets = {{'(',')'], {'[',']'}, {'{','}'}};

    for (char c : expr)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (st.empty() || brackets[st.top()] != c)
                return false;
            st.pop();
        }
    }
    return st.empty();
}

// 6. Implement stack with increment operation
class CustomStack
{
    vector<int> stack;
    int maxSize;

public:
    CustomStack(int size) : maxSize(size) {}

    void push(int x)
    {
        if (stack.size() < maxSize)
        {
            stack.push_back(x);
        }
    }

    int pop()
    {
        if (stack.empty())
            return -1;
        int val = stack.back();
        stack.pop_back();
        return val;
    }

    void increment(int k, int val)
    {
        int n = min(k, (int)stack.size());
        for (int i = 0; i < n; i++)
        {
            stack[i] += val;
        }
    }
};

// 7. Find the largest rectangle in histogram
int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    int maxArea = 0;
    int i = 0;

    while (i < heights.size())
    {
        if (st.empty() || heights[st.top()] <= heights[i])
        {
            st.push(i++);
        }
        else
        {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
    }

    while (!st.empty())
    {
        int height = heights[st.top()];
        st.pop();
        int width = st.empty() ? i : i - st.top() - 1;
        maxArea = max(maxArea, height * width);
    }

    return maxArea;
}

// 8. Remove duplicate letters maintaining lexicographical order
string removeDuplicateLetters(string s)
{
    vector<int> lastIndex(26, 0);
    vector<bool> seen(26, false);
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        lastIndex[s[i] - 'a'] = i;
    }

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (!seen[c - 'a'])
        {
            while (!st.empty() && c < st.top() &&
                   i < lastIndex[st.top() - 'a'])
            {
                seen[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(c);
            seen[c - 'a'] = true;
        }
    }

    string result;
    while (!st.empty())
    {
        result = st.top() + result;
        st.pop();
    }
    return result;
}