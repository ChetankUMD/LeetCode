#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> freq; // To track frequencies of elements
        vector<int> C(A.size(), 0); // Resultant prefix common array
        int n = A.size();
        int count = 0; // Count of common elements

        for (int i = 0; i < n; i++) {
            // Increment the frequency of A[i] and B[i]
            freq[A[i]]++;
            if (freq[A[i]] == 2) count++; // If A[i] appears in both A and B
            
            freq[B[i]]++;
            if (freq[B[i]] == 2) count++; // If B[i] appears in both A and B
            
            // Update the prefix common count at index i
            C[i] = count;
        }
        return C;
    }
};

int main() {
    // Example input
    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {3, 1, 2, 4};

    // Create an object of the Solution class
    Solution sol;

    // Call the function and get the result
    vector<int> result = sol.findThePrefixCommonArray(A, B);

    // Print the result
    cout << "Prefix Common Array: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
