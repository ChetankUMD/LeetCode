#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);

        // Calculate prefix products
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefix;// just store the prefix product in result[i]
            prefix *= nums[i];
        }

        // Calculate postfix products and multiply
        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= postfix; // multiply the current postfix product with the current number
            postfix *= nums[i];
        }

        return result;

        // required variables
    //     int n = nums.size();
    //     vector<int> result(n, 1);
    //     int final = 1;
    //     int flag = 0;
    //     int index = 0;
    //     int in = 0;


    // brute force
    //     // for(int i=0; i<n; i++){
    //     //     for (int j=0;j<n;j++){
    //     //         if(i!=j){
    //     //             result[i] = result[i] * nums[j];
    //     //         }
                
    //     //     }
    //     // }

    //     // optimized
    //     for(int num : nums){
    //         if(num != 0){
    //             final = final*num;
    //         }
    //         else{
    //             flag += 1;
    //             if(flag > 1){
    //                 result.assign(n,0);
    //                 return result;
    //             }
    //             in = index;
    //         }
    //         index++;
    //     }
    //     if(flag == 1){
    //         result.assign(n,0);
    //         result[in] = final;
    //         return result;
    //     }
    //     for (int i = 0; i< nums.size(); i++){
            
    //         if (nums[i] != 0){
    //             result[i] = final/nums[i];
    //         }
            
    //     }
    //     return result;
        
    }
};

// Main function for testing
int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> result1 = solution.productExceptSelf(nums1);
    cout << "Output for nums = [1, 2, 3, 4]: ";
    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;

    // Test case 2
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> result2 = solution.productExceptSelf(nums2);
    cout << "Output for nums = [-1, 1, 0, -3, 3]: ";
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
