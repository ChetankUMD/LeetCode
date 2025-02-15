#include <iostream>
#include <string>
#include <cctype>  // for isalnum, tolower

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0, j = n - 1;  // Start j at n-1 instead of n
        while (i < j) {
            // Move 'j' backward until you find an alphanumeric character
            while (i < j && !isalnum(s[j])) {
                j--;
            }
            // Move 'i' forward until you find an alphanumeric character
            while (i < j && !isalnum(s[i])) {
                i++;
            }
            // Debug print (optional):
            cout << s[i] << " " << s[j] << endl;

            // Compare letters in a case-insensitive way
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << "Enter a string to check for palindrome: ";
    string input;
    getline(cin, input);  // Read the entire line from stdin

    if (sol.isPalindrome(input)) {
        cout << "It's a palindrome" << endl;
    } else {
        cout << "Not a palindrome" << endl;
    }

    return 0;
}