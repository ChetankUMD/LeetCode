#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> arr = nums;       // Copy nums to arr
        sort(arr.begin(), arr.end()); // Sort arr in ascending order
        int gno = 0;                  // Group number
        unordered_map<int, queue<int>> group; // Stores groups of elements
        map<int, int> connect;                 // Maps each element to its group
        
        // Initialize the first group
        connect[arr[0]] = gno;
        group[gno].push(arr[0]);

        // Group elements based on the limit
        for (int i = 1; i < nums.size(); i++) {
            if (abs(arr[i] - arr[i - 1]) <= limit) {
                group[gno].push(arr[i]);
                connect[arr[i]] = gno;
            } else {
                gno++;
                group[gno].push(arr[i]);
                connect[arr[i]] = gno;
            }
        }

        // Reconstruct the lexicographically smallest array
        for (int i = 0; i < nums.size(); i++) {
            int ele = nums[i];
            nums[i] = group[connect[nums[i]]].front(); // Get the smallest element from the group
            group[connect[nums[i]]].pop();            // Remove the used element from the group
        }

        return nums;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4, 2, 1, 3};
    int limit = 2;

    vector<int> result = solution.lexicographicallySmallestArray(nums, limit);

    cout << "Lexicographically smallest array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
