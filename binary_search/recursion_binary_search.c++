#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return Rsearch(0, nums.size() - 1, target, nums);
    }

private:
    int Rsearch(int l, int h, int key, vector<int>& nums) {
        if (l > h) return -1; // Base case: Element not found

        int mid = l + (h - l) / 2; // Prevents integer overflow

        if (nums[mid] == key) return mid; // Base case: Element found

        if (nums[mid] < key) {
            return Rsearch(mid + 1, h, key, nums); // Search in right half
        } else {
            return Rsearch(l, mid - 1, key, nums); // Search in left half
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-5, 1, 3, 5, 7, 9, 12}; // Sorted array
    int target;

    cout << "Enter the number to search: ";
    cin >> target;

    int result = sol.search(nums, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}