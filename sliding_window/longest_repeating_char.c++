#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int longest = 0, l = 0;
        int maxfrq = 0;
        unordered_map<char, int> map;

        for (int r = 0; r < n; r++) {
            map[s[r]]++;
            maxfrq = max(maxfrq, map[s[r]]);
            cout << "Current max frequency: " << maxfrq << endl;

            // If the window size minus the max frequency character count is greater than k, shrink the window
            while ((r - l + 1) - maxfrq > k) {
                map[s[l]]--;
                l++;
            }

            longest = max(longest, r - l + 1);
        }
        return longest;
    }
};

// **Main Function**
int main() {
    Solution sol;

    string s;
    int k;
    
    cout << "Enter string: ";
    cin >> s;
    
    cout << "Enter k: ";
    cin >> k;

    // Compute and print result
    int result = sol.characterReplacement(s, k);
    cout << "Longest substring length after replacement: " << result << endl;

    return 0;
}