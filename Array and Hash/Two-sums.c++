#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    // std::vector<int> output(2,0);
        // for(int i =0; i < nums.size(); i++){
        //     for(int j =i; j < nums.size(); j++){
        //         if( i != j && nums[i]+nums[j] == target){
        //             output = {i ,j};
        //             return output;
        //         }
        //     }
        // }
        // return output;

        // std::unordered_map<int, int> numMap;
        // for(int i = 0; i<nums.size(); i++){
        //     int complement = target-nums[i];

        //     if (numMap.find(complement) != numMap.end()){
        //         return {numMap[complement], i};
        //     }

        //     numMap[nums[i]] = i;
        // }

        // return {};

        for(int i = 0; i<nums.size(); i++){
            int complement = target-nums[i];
            auto it = std::find(nums.begin()+i+1, nums.end(), complement);
            if (it!= nums.end()){
                return {static_cast<int>(std::distance(nums.begin(), it)), i};
            }
        }

        return {};
}

int main() {
    // Example 1
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> result1 = twoSum(nums1, target1);
    std::cout << "[" << result1[0] << ", " << result1[1] << "]" << std::endl;

    // Example 2
    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::vector<int> result2 = twoSum(nums2, target2);
    std::cout << "[" << result2[0] << ", " << result2[1] << "]" << std::endl;

    // Example 3
    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    std::vector<int> result3 = twoSum(nums3, target3);
    std::cout << "[" << result3[0] << ", " << result3[1] << "]" << std::endl;

    return 0;
}
