#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];

        // Step 1: Detect cycle in the sequence
        while (true) {
            slow = nums[slow];            // Move one step
            fast = nums[nums[fast]];      // Move two steps

            if (slow == fast) {           // Cycle detected
                break;
            }
        }

        // Step 2: Find the start of the cycle (duplicate number)
        int slow2 = nums[0];
        while (slow != slow2) {
            slow = nums[slow];    // Move one step
            slow2 = nums[slow2];  // Move one step
        }

        return slow;  // The duplicate number
    }
};

// Function to test the solution
int main() {
    Solution solution;
    
    // Example test case
    vector<int> nums = {1, 3, 4, 2, 2}; // Contains duplicate '2'
    
    cout << "Duplicate Number: " << solution.findDuplicate(nums) << endl;

    return 0;
}