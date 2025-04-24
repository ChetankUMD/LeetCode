#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto n : nums) {
            min_heap.push(n);
            if (min_heap.size() > k) {
                min_heap.pop();  // Keep only the k largest elements
            }
        }
    }
    
    int add(int val) {
        min_heap.push(val);
        if (min_heap.size() > k) {
            min_heap.pop();  // Remove smallest among k+1 elements
        }
        return min_heap.top();  // The kth largest is the smallest in min-heap
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    int k = 3;

    KthLargest kthLargest(k, nums);

    cout << "Add 3: " << kthLargest.add(3) << endl;   // returns 4
    cout << "Add 5: " << kthLargest.add(5) << endl;   // returns 5
    cout << "Add 10: " << kthLargest.add(10) << endl; // returns 5
    cout << "Add 9: " << kthLargest.add(9) << endl;   // returns 8
    cout << "Add 4: " << kthLargest.add(4) << endl;   // returns 8

    return 0;
}