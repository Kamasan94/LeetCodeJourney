#include<iostream>
#include<vector>
using namespace std;

// Given a binary array nums, return the maximum number of consecutive 1's in the array.

// Example 1:
// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
// Example 2:

// Input: nums = [1,0,1,1,0,1]
// Output: 2
 
// Constraints:
// 1 <= nums.length <= 10^5
// nums[i] is either 0 or 1.

class Solution {
    public:
        int findMaxConsecutiveOnes(vector<int>& nums) {
            int count = 0;
            int max = 0;
            for(int num : nums){
                if(num == 1){
                    count ++;
                }
                else {
                    if(count > max){
                        max = count;
                    }
                    count = 0;
                }
            }
            if(count > max){
                max = count;
            }
            return max;
        }
    };


int main(){
    vector<int> nums = {1,1,0,1,1,1};
    Solution s;
    cout << s.findMaxConsecutiveOnes(nums) << endl;
}