#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // if(nums.size() == 0) return 0;
        // unordered_set<int> set(nums.begin(), nums.end());
        // int result = 0;
        // for(auto num : set){
        //     if(set.find(num -1) == set.end()){
        //         int loopnum = num;
        //         int maxlen = 1;

        //         while(set.find(loopnum + 1) != set.end()){
        //             loopnum += 1;
        //             maxlen += 1;
        //         }

        //         result = max(result, maxlen);
        //     }
        // }
        // return result;
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int result = 1;
        int loopmax = 1;
        for(int i =0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                continue;
            }
            else if(nums[i] + 1 == nums[i+1]){
                loopmax++;
            }
            else {
                loopmax = 1;
            }
            result = max(result, loopmax);
        }
        return result;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "Longest consecutive sequence length: " << solution.longestConsecutive(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {0, -1, 1, 2, -2, -3};
    cout << "Longest consecutive sequence length: " << solution.longestConsecutive(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {1, 2, 0, 1};
    cout << "Longest consecutive sequence length: " << solution.longestConsecutive(nums3) << endl;

    return 0;
}
