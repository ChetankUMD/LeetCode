#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());
        
        int n = merged.size();
        cout << "Middle element: " << merged[n/2] << endl;  // Debug print

        if (n % 2 == 0) {
            return (merged[n/2 - 1] + merged[n/2]) / 2.0;  // Floating point division
        } else {
            return merged[n/2];  // Odd case, median is the middle element
        }
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Median: " << sol.findMedianSortedArrays(nums1, nums2) << endl;  // Expected: 2.0

    // Test Case 2
    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << "Median: " << sol.findMedianSortedArrays(nums3, nums4) << endl;  // Expected: 2.5

    // Test Case 3
    vector<int> nums5 = {0, 0};
    vector<int> nums6 = {0, 0};
    cout << "Median: " << sol.findMedianSortedArrays(nums5, nums6) << endl;  // Expected: 0.0

    // Test Case 4
    vector<int> nums7 = {2};
    vector<int> nums8 = {};
    cout << "Median: " << sol.findMedianSortedArrays(nums7, nums8) << endl;  // Expected: 2.0

    return 0;
}