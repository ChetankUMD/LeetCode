#include <iostream>
#include <vector>
#include <algorithm>  // for std::sort
#include <set>        // for std::set (used in the commented code)
using namespace std;

/**
 * The Solution class encapsulates the logic for finding all unique
 * triplets in an integer array that add up to zero.
 */
class Solution {
public:
    /**
     * threeSum:
     *   - Sorts the input array.
     *   - Uses a for loop to fix one number at a time (nums[i]).
     *   - Then uses a two-pointer approach (l, r) to find pairs that
     *     sum with nums[i] to zero.
     *   - Avoids duplicates by skipping elements that are the same as
     *     previously used ones.
     *
     * @param nums Reference to a vector of integers (input array).
     * @return A vector of vectors, each containing a valid triplet.
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        // 1. Sort the array to easily handle duplicates and use two pointers.
        sort(nums.begin(), nums.end());

        // This will hold our resulting triplets.
        vector<vector<int>> res;

        // 2. Loop over each element to use as a fixed element in the triplet.
        for (int i = 0; i < n; i++) {
            // Avoid duplicates for the 'i' element:
            // If current element is the same as the previous one, skip.
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Two pointers: 
            //   l starts right after i,
            //   r starts at the end.
            int l = i + 1;
            int r = n - 1;

            // 3. Use two-pointer approach to find valid pairs.
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    // If the triplet sums to zero, we add it to our result.
                    res.push_back({nums[i], nums[l], nums[r]});

                    // Move the pointers inward.
                    l++;
                    r--;

                    // Skip duplicates for the 'l' pointer.
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                } 
                else if (sum > 0) {
                    // If sum is too large, move r left to reduce the sum.
                    r--;
                } 
                else {
                    // If sum is too small, move l right to increase the sum.
                    l++;
                }
            }
        }

        // ==============================
        // BRUTE FORCE APPROACH (COMMENTED)
        // ==============================
        /*
        // set<vector<int>> resSet;
        // for (int i = 0; i < n; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         for(int k = j + 1; k < n; k++) {
        //             if (nums[i] + nums[j] + nums[k] == 0) {
        //                 // Insert the triplet into a set, which avoids duplicates.
        //                 // Because the array might not be sorted when entering the set,
        //                 // first create a temporary vector, sort it, then insert.
        //                 vector<int> triplet = {nums[i], nums[j], nums[k]};
        //                 sort(triplet.begin(), triplet.end());
        //                 resSet.insert(triplet);
        //             }
        //         }
        //     }
        // }
        //
        // // Convert the set of vectors back to a vector of vectors.
        // vector<vector<int>> resBrute(resSet.begin(), resSet.end());
        // return resBrute;
        */

        // 4. Return the list of unique triplets.
        return res;
    }
};

/**
 * main:
 *   - Reads input from the user:
 *       1) The number of elements 'n'.
 *       2) 'n' integers into a vector.
 *   - Invokes the 'threeSum' method from the 'Solution' class.
 *   - Prints out each triplet found.
 */
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // Read the elements into a vector.
    vector<int> nums(n);
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Create an object of the Solution class.
    Solution sol;

    // Call threeSum and store the result.
    vector<vector<int>> result = sol.threeSum(nums);

    // Print the result.
    cout << "\nTriplets that sum to zero:\n";
    for (const auto& triplet : result) {
        cout << "[ ";
        for (int val : triplet) {
            cout << val << " ";
        }
        cout << "]\n";
    }

    return 0; // End of program
}