#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> map;
        int longest = 0, l = 0;

        for (int r = 0; r < n; r++) {
            map[s[r]]++; // Add current character to map

            // If character repeats, shrink the window from the left
            while (map[s[r]] > 1) {
                map[s[l]]--;
                l++;
            }

            // Update longest substring length
            longest = max(longest, r - l + 1);
        }
        
        return longest;
    }
};

// **Main Function**
int main() {
    Solution sol;
    
    // Test cases
    string s;
    cout << "Enter a string: ";
    cin >> s;

    // Compute and print result
    int result = sol.lengthOfLongestSubstring(s);
    cout << "Length of the longest substring without repeating characters: " << result << endl;

    return 0;
}