#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> max; // max-heap for the smaller half
    priority_queue<int, vector<int>, greater<int>> min; // min-heap for the larger half

    MedianFinder() {
    }
    
    void addNum(int num) {
        max.push(num);
        // Ensure the largest of the smaller half is less than the smallest of the larger half`
        if (!min.empty() && min.top() < max.top()) {
            min.push(max.top());
            max.pop();
        }
        
        // Balance the heaps
        if (max.size() > min.size() + 1) {
            min.push(max.top());
            max.pop();
        }
        if (min.size() > max.size() + 1) {
            max.push(min.top());
            min.pop();
        }
    }
    
    double findMedian() {
        int maxn = max.size();
        int minn = min.size();

        if (maxn == minn) {
            return (max.top() + min.top()) / 2.0;
        } else if (maxn > minn) {
            return max.top();
        } else {
            return min.top();
        }
    }
};

int main() {
    MedianFinder mf;

    mf.addNum(1);
    mf.addNum(2);
    cout << "Median after [1, 2]: " << mf.findMedian() << endl; // 1.5

    mf.addNum(3);
    cout << "Median after [1, 2, 3]: " << mf.findMedian() << endl; // 2

    mf.addNum(4);
    cout << "Median after [1, 2, 3, 4]: " << mf.findMedian() << endl; // 2.5

    mf.addNum(5);
    cout << "Median after [1, 2, 3, 4, 5]: " << mf.findMedian() << endl; // 3

    return 0;
}