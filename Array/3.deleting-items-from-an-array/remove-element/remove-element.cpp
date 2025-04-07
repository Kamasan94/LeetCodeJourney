// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. 
// Then return the number of elements in nums which are not equal to val.

// Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

// Change the array nums such that the first k elements of nums contain the elements which are not equal to val. 
// The remaining elements of nums are not important as well as the size of nums.
// Return k.
// Custom Judge:

// The judge will test your solution with the following code:

// int[] nums = [...]; // Input array
// int val = ...; // Value to remove
// int[] expectedNums = [...]; // The expected answer with correct length.
//                             // It is sorted with no values equaling val.

// int k = removeElement(nums, val); // Calls your implementation

// assert k == expectedNums.length;
// sort(nums, 0, k); // Sort the first k elements of nums
// for (int i = 0; i < actualLength; i++) {
//     assert nums[i] == expectedNums[i];
// }
// If all assertions pass, then your solution will be accepted.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        int last = length - 1;
        if(last == 0 && nums[last] == val){
            return 0;
        }
        for(int i = 0; i<=last && last != 0; i++){
            if(nums[i] == val){
                while(last >= 0 && nums[last] == val && i!=last ){
                    last--;
                }
                if(last > 0){
                    nums[i] = nums[last];
                    last--;
                }
                else if (last <= 0){
                    return 0;
                }
            }
        }
        return last + 1;
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
    vector<int> nums = {4,5}; // Input array
    int val = 5; // Value to remove
    vector<int>expectedNums = {}; // The expected answer with correct length.
                                    // It is sorted with no values equaling val.
    
    Solution s;
    int k = s.removeElement(nums, val); // Calls your implementation
    
    s.printVector(nums);
}