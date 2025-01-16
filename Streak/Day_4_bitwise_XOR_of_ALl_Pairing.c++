#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0, xor2 = 0;
        int res = 0;

        // If nums2's size is odd, nums1 contributes to the result
        if (nums2.size() % 2 == 1) {
            for (int num : nums1) {
                xor1 ^= num;
            }
            res ^= xor1;
        }

        // If nums1's size is odd, nums2 contributes to the result
        if (nums1.size() % 2 == 1) {
            for (int num : nums2) {
                xor2 ^= num;
            }
            res ^= xor2;
        }

        return res;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {2, 4, 6};
    vector<int> nums2 = {1, 3};
    cout << "Result for Example 1: " << solution.xorAllNums(nums1, nums2) << endl;

    // Example 2
    nums1 = {5, 7};
    nums2 = {1, 3, 9};
    cout << "Result for Example 2: " << solution.xorAllNums(nums1, nums2) << endl;

    // Example 3
    nums1 = {1, 2, 3};
    nums2 = {4, 5, 6, 7};
    cout << "Result for Example 3: " << solution.xorAllNums(nums1, nums2) << endl;

    return 0;
}
