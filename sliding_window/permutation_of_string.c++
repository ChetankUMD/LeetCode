#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m > n) return false; // s1 cannot be a permutation if it's longer than s2

        unordered_map<char, int> map1, map2;

        // Build frequency map for s1
        for (char c : s1) {
            map1[c]++;
        }

        // Sliding window for s2
        for (int r = 0; r < n; r++) {
            map2[s2[r]]++; // Add current character to window

            // Once the window size exceeds `m`, remove the leftmost character
            if (r >= m) {
                if (map2[s2[r - m]] == 1) {
                    map2.erase(s2[r - m]); // Remove key if frequency is zero
                } else {
                    map2[s2[r - m]]--;
                }
            }

            // Check if the frequency maps match
            if (map1 == map2) return true;
        }

        return false;
    }
};

// **Main Function**
int main() {
    Solution sol;

    string s1, s2;
    cout << "Enter s1: ";
    cin >> s1;
    cout << "Enter s2: ";
    cin >> s2;

    if (sol.checkInclusion(s1, s2)) {
        cout << "s1's permutation is a substring of s2." << endl;
    } else {
        cout << "s1's permutation is NOT a substring of s2." << endl;
    }

    return 0;
}