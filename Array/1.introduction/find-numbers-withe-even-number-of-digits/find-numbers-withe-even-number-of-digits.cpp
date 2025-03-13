#include<iostream>
#include<vector>
using namespace std;
// Given an array nums of integers, return how many of them contain an even number of digits.

// Example 1:
// Input: nums = [12,345,2,6,7896]
// Output: 2
// Explanation: 
// 12 contains 2 digits (even number of digits). 
// 345 contains 3 digits (odd number of digits). 
// 2 contains 1 digit (odd number of digits). 
// 6 contains 1 digit (odd number of digits). 
// 7896 contains 4 digits (even number of digits). 
// Therefore only 12 and 7896 contain an even number of digits.

// Example 2:
// Input: nums = [555,901,482,1771]
// Output: 1 
// Explanation: 
// Only 1771 contains an even number of digits.
 
// Constraints:
// 1 <= nums.length <= 500
// 1 <= nums[i] <= 10^5

class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int count = 0;
            for(int num: nums){
                if(num / 10 > 0 && num / 10 < 10){
                    count++;
                }
                else if (num / 1000 > 0 && num / 1000 < 10){
                    count++;
                }
                else if (num / 100000 > 0 && num / 100000 < 10)
                {
                    count++;
                }
                
            }
            return count;
        }
    };

int main(){
    vector<int> nums = {18853,98579,84784,79454,10299,58256,96202,81050,92048,6855,93106,84110,24894,60975,48451,55448,99647,87199,66581,3063,36963,36696,40852,79534,79591,23124,65905,31938,61166,98292,29774,12087,6811,64437,266,3028,64007,48221,7531,56025,35611,8206,85401,39255,66701,73154,12989,46684,51753,3600,48464,13338,66088,98450,19728,42616,57521,67969,20385,13611,95241,90068,21711,82577,65270,37433,87718,42349,82668,56912,91325,74395,34160,86971,93206,47751,88441,12074,5360,62085,4748,82707,64559,54395,77052,42592,59440,769,3814,78624,52859,13084,37725,66096,26931,74020,7370,63389,3549,33970,17627,4607,58533,97358,52414,46379,1989,63322,78122,8180,49827,251,41683,61762,91819,46191,30481,97541,15913,41795,60096,61109,87217,25375,40960,38542,72039,91298,44093,67882,93683,73792,87239,22308,94178,70032,31901,63034,14015,54571,63013,81331,9737,63605,22180,28964,78196,27752,76249,85811,97485,40704,48937,76064,39849,7596,97440,35378,4764,47483};
    Solution s;
    cout << s.findNumbers(nums) << endl;
}