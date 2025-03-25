// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

// Example 1:

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
// Example 2:

// Input: nums1 = [1], m = 1, nums2 = [], n = 0
// Output: [1]
// Explanation: The arrays we are merging are [1] and [].
// The result of the merge is [1].
// Example 3:

// Input: nums1 = [0], m = 0, nums2 = [1], n = 1
// Output: [1]
// Explanation: The arrays we are merging are [] and [1].
// The result of the merge is [1].
// Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

// Constraints:

// nums1.length == m + n
// nums2.length == n
// 0 <= m, n <= 200
// 1 <= m + n <= 200
// -109 <= nums1[i], nums2[j] <= 109
 

// Follow up: Can you come up with an algorithm that runs in O(m + n) time?

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int inum1 = 0, inum2 = 0, inum1p2 = m;
            int nums2left = n;
            if(n == 0){
                return;
            }
            if(m == 0){
                for(int i=0; i<n; i++){
                    nums1[i] = nums2[i];
                }
                return;
            }
            while(nums2left>0){
                if(nums1[inum1] <= nums2[inum2] && inum1 != inum1p2){
                    inum1++;
                }
                else{
                    nums1[inum1p2] = nums1[inum1]; //should replace 0
                    nums1[inum1] = nums2[inum2];
                    inum2++;
                    nums2left--;
                    if(inum1 == inum1p2){
                        inum1++;
                    }
                    inum1p2++;    
                }
            }
            while(inum1p2 != inum1){
                if(nums1[inum1] > nums1[inum1p2]){
                    
                }
            }
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
    vector<int> v1 = {1,2,3,0,0,0};
    vector<int> v2  = {2,5,6};
    Solution s;
    s.merge(v1, 3, v2, 3);
    printVector(v1);
    return 0;
}