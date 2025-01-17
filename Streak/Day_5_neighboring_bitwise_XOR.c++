#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        // Case when n is 1
        if (n == 1) return derived[0] == 0;

        // Check validity for two possible starting values of the original array
        vector<int> original(n, 0);
        bool isValid = true;

        // Check for original[0] = 0
        for (int i = 0; i < n; ++i) {
            int next = (i + 1) % n;
            original[next] = derived[i] ^ original[i];
        }
        if ((original[0] ^ original[n - 1]) == derived[n - 1]) return true;

        // Check for original[0] = 1
        original[0] = 1;
        isValid = true;
        for (int i = 0; i < n; ++i) {
            int next = (i + 1) % n;
            original[next] = derived[i] ^ original[i];
        }
        return (original[0] ^ original[n - 1]) == derived[n - 1];
        // int n = derived.size();
        // int ans = 0;
        // for(int i = 0; i < n; i++){
        //     ans ^= derived[i];
        // }
        // if(ans == 0)return true;
        // return false;
        // bool doesValidArrayExist(vector<int>& derived) {
        // int sum = accumulate(derived.begin(), derived.end(), 0);
        // return sum % 2 == 0;
    }

};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> derived1 = {1, 1, 0};
    cout << (solution.doesValidArrayExist(derived1) ? "true" : "false") << endl;

    // Test Case 2
    vector<int> derived2 = {1, 1};
    cout << (solution.doesValidArrayExist(derived2) ? "true" : "false") << endl;

    // Test Case 3
    vector<int> derived3 = {1, 0};
    cout << (solution.doesValidArrayExist(derived3) ? "true" : "false") << endl;

    // Additional Test Case
    vector<int> derived4 = {0, 0, 0};
    cout << (solution.doesValidArrayExist(derived4) ? "true" : "false") << endl;

    return 0;
}
