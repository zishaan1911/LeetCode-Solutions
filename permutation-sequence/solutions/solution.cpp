#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        
        for (int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        
        k = k - 1;
        string res = "";
        
        while (true) {
            // Determine the index of the current digit
            // res += numbers[index]
            res += to_string(numbers[k / fact]);
            
            // Remove used number from the available list
            numbers.erase(numbers.begin() + (k / fact));
            
            if (numbers.size() == 0) break;
            
            // Update k for the next iteration
            k = k % fact;
            // Update factorial to (n-2)!, then (n-3)!, etc.
            fact = fact / numbers.size();
        }
        
        return res;
    }
};