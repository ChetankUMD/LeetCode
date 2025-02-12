#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // using hasp map and bucteck sort where we store the frequencies in values 
        std::vector<int> res;
        std::unordered_map<int, int> count;
        std::vector<std::vector<int>> freq(nums.size()+1);

        for (int n :nums){
            count[n]++;
        }
        for(const auto& it : count){
            freq[it.second].push_back(it.first);
        }
        for (int i = freq.size()-1;i>0;--i){
            for (int n : freq[i]){
                res.push_back(n);
                if(res.size() == k){
                    return res;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    std::vector<int> result = sol.topKFrequent(nums, k);

    std::cout << "Top " << k << " frequent elements are:\n";
    for (int n : result) {
        std::cout << n << " ";
    }

    return 0;
}
