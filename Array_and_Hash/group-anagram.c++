#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        // std::unordered_map<std::string, std::vector<std::string>> anagramGroups;

        // // Group anagrams using a sorted string as the key
        // for (const std::string& str : strs) {
        //     std::string sortedStr = str;
        //     std::sort(sortedStr.begin(), sortedStr.end());
        //     anagramGroups[sortedStr].push_back(str);
        // }

        // // Collect the grouped anagrams into the result vector
        // std::vector<std::vector<std::string>> result;
        // for (auto& group : anagramGroups) {
        //     result.push_back(group.second);
        // }

        // return result;
        // std::unordered_map<std::string, std::vector<std::string>> res;

        // for (const auto& s : strs){
        //     std::vector<int> count(26,0);
        //     for (char c : s){
        //         count[c - 'a']++;
        //     }
        //     std::string key = std::to_string(count[0]);
        //     for (int i =1; i<26;i++){
        //         key += ',' + std::to_string(count[i]);
        //     }
        //     res[key].push_back(s);
        // }
        // std::vector<std::vector<std::string>> result;
        // for(const auto& pair :res){
        //     result.push_back(pair.second);
        // }
        // result;



        unordered_map<string, vector<string>> map;

        for(auto s : strs){
            string sorted = s;
            sort(sorted.begin(), sorted.end());

            map[sorted].push_back(s); 
        }

        vector<vector<string>> res;
        for(auto s : map){
            res.push_back(s.second);
        }

        return res;
    }
};


// Assuming the Solution class is already defined as above
int main() {
    // Input vector of strings
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // Create an instance of the Solution class
    Solution solution;

    // Call the groupAnagrams function
    std::vector<std::vector<std::string>> result = solution.groupAnagrams(strs);

    // Print the result
    std::cout << "Grouped Anagrams:\n";
    for (const auto& group : result) {
        std::cout << "[";
        for (const auto& word : group) {
            std::cout << word << " ";
        }
        std::cout << "]\n";
    }

    return 0;
}
