#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int i = 0;

        while (i < s.length()) {
            int left = i - 1;
            int right = i + 1;

            // Check if there are valid characters to remove
            while (left >= 0 && right < s.length() && s[i] == s[left] && s[i] == s[right]) {
                // Erase characters from left and right
                s.erase(right, 1); // Remove right character first
                s.erase(left, 1);  // Remove left character
                right--;           // Adjust right after erasure
                i--;               // Move to the previous index to recheck
            }
            i++; // Move to the next character
        }

        // Return the remaining string length
        return s.length();
    }
    // int minimumLength(string s) {
    //     int n = s.length();
    //     int i = 0;

    //     while (i < s.length()) {
    //         int left = i - 1;
    //         int right = i + 1;

    //         // Check if there are valid characters to remove
    //         while (left >= 0 && right < s.length() && s[i] == s[left] && s[i] == s[right]) {
    //             // Erase characters from left and right
    //             s.erase(right, 1); // Remove right character first
    //             s.erase(left, 1);  // Remove left character
    //             right--;           // Adjust right after erasure
    //             i--;               // Move to the previous index to recheck
    //         }
    //         i++; // Move to the next character
    //     }

    // // Return the remaining string length
    // return s.length();
    //     // int n = s.length();
    //     // for(int i =1;i<n-1;i++){
    //     //     int left = i-1;
    //     //     int right = i+1;
    //     //     while(left >= 0 && right < s.length()){
    //     //         if(s[i] == s[left] && s[i] == s[right]){
    //     //             s.erase(left, 1);
    //     //             s.erase(right - 1, 1);
    //     //             i = left;
    //     //             n = s.length();
    //     //             break;
    //     //         }
    //     //         left--;
    //     //         right++;
    //     //     }
            
    //     //     cout << s << " ";
    //     // }
        
    //     // while(left<right && s[left] == s[right]){
    //     //     char current = s[left];

    //     //     while(left < right && s[left] == current){
    //     //         s.erase(left, 1);
    //     //         right--;
    //     //     }

    //     //     while(left <=right && s[right] == current){
    //     //         s.erase(right, 1);
    //     //         right--;
    //     //     }
    //     // }
    //     return s.length();
    //     // int size = s.length();
    //     // vector<char> str(s.begin(), s.end());
    //     // sort(str.begin(), str.end());
    //     // for (int i =0 ;i<str.size(); i++){
    //     //     int no = count(str.begin()+i, str.end(), str[i]);
    //     //     if(no >= 3){
    //     //         size = size -2;
    //     //         i = i +2;
    //     //     }
    //     //     no = 0;
    //     // }
    //     // return size;
    // }
};