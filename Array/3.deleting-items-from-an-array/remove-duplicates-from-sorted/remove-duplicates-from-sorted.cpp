// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

// Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
// Return k.

// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i1 = 0;
        int i2 = 1;
        bool dup = false;
        
        if(nums.size() == 2){
            if(nums[i1] == nums[i2])
                return 1;
            else
                return 2;
        }
        
        while(i2 < nums.size()-1) {
            if(nums[i1] == nums[i2])
                i2++;

            if(nums[i1] !=  nums[i2]){
                nums[i1 + 1] = nums[i2];
                i1++;
            }

        }
        return i1+1;
    }
};


int main() {

}