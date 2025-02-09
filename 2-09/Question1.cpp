#include <iostream>
#include <string>

using namespace std;

// Function to check if a given string is a palindrome
bool isPalindrome(const string &s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// Function to find the index of the character to remove to make the string a palindrome
int palindromeIndex(const string &s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            // Check if removing the character at 'left' or 'right' makes it a palindrome
            if (isPalindrome(s, left + 1, right)) {
                return left;
            } else if (isPalindrome(s, left, right - 1)) {
                return right;
            } else {
                return -1;
            }
        }
        left++;
        right--;
    }
    return -1; // Already a palindrome
}

int main() {
    int q;
    cout << "Enter the number of queries: ";
    cin >> q;
    cin.ignore(); // To consume the newline character after the integer input

    for (int i = 0; i < q; ++i) {
        string s;
        cout << "Enter the query string: ";
        getline(cin, s);

        int result = palindromeIndex(s);
        cout << "Index to remove: " << result << endl;
    }

    return 0;
}
