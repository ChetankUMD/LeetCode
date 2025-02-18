#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int muiltofN(int n) {
        if ( n == 0 ) return 1;
        return n * muiltofN(n-1);
    }

    int sumOfN(int n) {
        if ( n == 0 ) return 0;
        return n + sumOfN(n-1);
    }

    int fibonacci(int n){
        if(n == 0) return 0;
        if(n == 1) return 1;
        return fibonacci(n-1) + fibonacci(n-2);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input: number of bars
    int n;
    cin >> n;

    Solution sol;
    int resultSum = sol.sumOfN(n);
    int resultMulti = sol.muiltofN(n); ; 

    // Print the result
    cout << resultSum << "\n";
    cout << resultMulti << "\n";

    return 0;
}