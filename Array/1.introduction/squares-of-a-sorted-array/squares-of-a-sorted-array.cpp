#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

// Example 1:
// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].

// Example 2:
// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]
 
// Constraints:
// 1 <= nums.length <= 10^4
// -104 <= nums[i] <= 10^4
// nums is sorted in non-decreasing order.

// Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?

class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            vector<int> solution = {};
            vector<int>::iterator begin,end;
            int beginValue, endValue;

            begin = nums.begin();
            end = nums.end()-1;
                for(int i = 0; i < nums.size(); i++ ){
                    beginValue = pow(*begin,2);
                    endValue = pow(*end,2);
                    if(beginValue > endValue){
                        solution.insert(solution.begin(),beginValue);
                        begin++;
                    }
                    else{
                        solution.insert(solution.begin(),endValue);
                        end--;
                    }
                }
            return solution;
        }
    };

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

int main(){
    vector<int> nums = {-4,-1,0,3,10};
    Solution s;
    vector<int> solution = s.sortedSquares(nums);
    printVector(solution);
}