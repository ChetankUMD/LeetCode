#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagramGroups;

        // Group anagrams using a sorted string as the key
        for (const std::string& str : strs) {
            std::string sortedStr = str;
            std::sort(sortedStr.begin(), sortedStr.end());
            anagramGroups[sortedStr].push_back(str);
        }

        // Collect the grouped anagrams into the result vector
        std::vector<std::vector<std::string>> result;
        for (auto& group : anagramGroups) {
            result.push_back(group.second);
        }

        return result;
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
