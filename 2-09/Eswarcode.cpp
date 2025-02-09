#include <iostream>
#include <string>
using namespace std;

int palindromeIndex(string s) {
    int n = s.length();
    
    // First check if it's already a palindrome
    bool isPalindrome = true;
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n-1-i]) {
            isPalindrome = false;
            break;
        }
    }
    if (isPalindrome) return -1;
    
    // Try removing each character and check if resulting string is palindrome
    for (int i = 0; i < n; i++) {
        bool canBePalindrome = true;
        // Check if string without character at index i is palindrome
        for (int j = 0, k = 0; j < n-1; j++, k++) {
            if (k == i) k++; // Skip the removed character
            if (j >= (n-1)/2) break;
            
            // Compare characters from both ends excluding index i
            int opposite = n-1-j;
            if (opposite > i) opposite--;
            
            if (s[k] != s[opposite]) {
                canBePalindrome = false;
                break;
            }
        }
        if (canBePalindrome) return i;
    }
    
    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
