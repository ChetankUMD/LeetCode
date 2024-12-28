#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = i + 1; j < nums.size(); j++) {
//                 if (nums[i] == nums[j]) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for(int num : nums){
            cout << seen.count(num) << endl;
            if (seen.count(num)){
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    cout << "Test Case 1: " << (solution.containsDuplicate(nums1) ? "True" : "False") << endl; // Output: True
    cout << "Test Case 2: " << (solution.containsDuplicate(nums2) ? "True" : "False") << endl; // Output: False
    cout << "Test Case 3: " << (solution.containsDuplicate(nums3) ? "True" : "False") << endl; // Output: True

    return 0;
}
