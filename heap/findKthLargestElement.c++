#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min heap to store the k largest elements
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (auto n : nums) {
            min_heap.push(n);

            // Keep only the k largest elements in the heap
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        // The top of the heap is the k-th largest element
        return min_heap.top();
    }
};

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    Solution sol;
    int result = sol.findKthLargest(nums, k);

    cout << "The " << k << "th largest element is: " << result << endl;

    return 0;
}