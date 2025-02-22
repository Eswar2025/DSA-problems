#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
 * Parentheses Matching Using Stack
 *
 * Problem Description:
 * Given a string containing brackets/parentheses, determine if all brackets
 * are properly matched and nested.
 *
 * Valid Examples:
 * - "()"
 * - "({[]})"
 * - "((()))"
 *
 * Invalid Examples:
 * - "("      (incomplete)
 * - "({[})"  (mismatched)
 * - ")("     (wrong order)
 *
 * Algorithm Approach:
 * 1. Scan string from left to right
 * 2. Push opening brackets onto stack
 * 3. For closing brackets, check if matches top of stack
 * 4. Stack should be empty at end for valid expression
 */
class ParenthesesChecker
{
public:
    /* Main function to check if brackets are balanced
     *
     * Time Complexity: O(n) where n is length of string
     * Space Complexity: O(n) in worst case (all opening brackets)
     *
     * Returns: true if expression is valid, false otherwise
     */
    bool isBalanced(string expr)
    {
        stack<char> s; // Using STL stack for simplicity

        // Traverse each character in the expression
        for (char c : expr)
        {
            if (isOpenBracket(c))
            {
                // For opening bracket, push to stack
                s.push(c);
            }
            else if (isCloseBracket(c))
            {
                // For closing bracket:
                // 1. Check if stack is empty (no matching open bracket)
                // 2. Check if matches with top of stack
                if (s.empty() || !isMatching(s.top(), c))
                {
                    return false;
                }
                s.pop(); // Remove matched opening bracket
            }
        }

        // Expression is valid only if stack is empty
        // (all brackets have been matched)
        return s.empty();
    }

private:
    /* Helper function to identify opening brackets
     * Supports multiple types of brackets: (), [], {}
     */
    bool isOpenBracket(char c)
    {
        return (c == '(' || c == '{' || c == '[');
    }

    /* Helper function to identify closing brackets
     * Supports multiple types of brackets: (), [], {}
     */
    bool isCloseBracket(char c)
    {
        return (c == ')' || c == '}' || c == ']');
    }

    /* Helper function to check if brackets match
     *
     * Parameters:
     * - open: Opening bracket from stack
     * - close: Current closing bracket being processed
     *
     * Returns: true if brackets form a valid pair
     */
    bool isMatching(char open, char close)
    {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }
};

/* Main function demonstrating various test cases
 * Shows both valid and invalid expressions
 */
int main()
{
    ParenthesesChecker checker;

    // Test cases demonstrating different scenarios
    string expressions[] = {
        "{[()]}",       // Valid: properly nested
        "{[(])}",       // Invalid: mismatched brackets
        "{{[[(())]]}}", // Valid: multiple nested brackets
        "(",            // Invalid: incomplete
        "}",            // Invalid: no opening bracket
        "(()))",        // Invalid: extra closing bracket
        ""              // Valid: empty string
    };

    // Test each expression
    for (const string &expr : expressions)
    {
        cout << "Expression: " << expr << endl;
        if (checker.isBalanced(expr))
            cout << "Yes it is Balanced" << endl;
        else
            cout << "No it is Not Balanced" << endl;
        cout << endl;
    }

    return 0;
}