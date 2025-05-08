// Given an array arr of integers, check if there exist two indices i and j such that :

// i != j
// 0 <= i, j < arr.length
// arr[i] == 2 * arr[j]
 

// Example 1:

// Input: arr = [10,2,5,3]
// Output: true
// Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
// Example 2:

// Input: arr = [3,1,7,11]
// Output: false
// Explanation: There is no i and j that satisfy the conditions.
 

// Constraints:

// 2 <= arr.length <= 500
// -10^3 <= arr[i] <= 10^3

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        std::unordered_map<int, int> u;
        for(int i = 0; i < arr.size(); i++){
            if(u[arr[i*2]])
                return true;
            else
                u[i]++;
        }
        return false;
    }

    void printVector(vector<int>& solution){
        int index = 0;
        cout<<'[';
        for(int num : solution){
            cout << num;
            if(index != solution.size() -1){
                cout << ' ';
            } 
            index++;
        }
        cout<< ']' << endl;
    }
};

int main() {
    vector<int> nums = {10,2,5,3}; // Input array
    
    Solution s;
    bool k = s.checkIfExist(nums); // Calls your implementation
    cout << k << endl;  
    cout << "ciao"; 

}