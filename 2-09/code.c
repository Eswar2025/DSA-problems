#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Helper function to check if string is palindrome when skipping index i
bool isPalindromeWithSkip(const char *s, int len, int skipIndex)
{
    int left = 0;
    int right = len - 1;

    while (left < right)
    {
        // Adjust indices if they match the skip index
        if (left == skipIndex)
            left++;
        if (right == skipIndex)
            right--;

        if (left < right)
        {
            if (s[left] != s[right])
            {
                return false;
            }
            left++;
            right--;
        }
    }
    return true;
}

int palindromeIndex(const char *s)
{
    int len = strlen(s);

    // First check if already palindrome
    bool isAlreadyPalindrome = true;
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - 1 - i])
        {
            isAlreadyPalindrome = false;
            break;
        }
    }
    if (isAlreadyPalindrome)
        return -1;

    // Try removing each character and check if resulting string is palindrome
    for (int i = 0; i < len; i++)
    {
        if (isPalindromeWithSkip(s, len, i))
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    // Test cases
    char test1[] = "bcbc";
    char test2[] = "aaab";
    char test3[] = "baa";
    char test4[] = "aaa";

    printf("Test 1 (%s): %d\n", test1, palindromeIndex(test1)); // Should print 0 or 3
    printf("Test 2 (%s): %d\n", test2, palindromeIndex(test2)); // Should print 3
    printf("Test 3 (%s): %d\n", test3, palindromeIndex(test3)); // Should print 0
    printf("Test 4 (%s): %d\n", test4, palindromeIndex(test4)); // Should print -1

    return 0;
}