#include<iostream>
#include<vector>
using namespace std;

// Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

// Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.
// Example 1:

// Input: arr = [1,0,2,3,0,4,5,0] size = 8 dups = 2
// Output: [1,0,0,2,3,0,0,4]
// Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
// Example 2:
  
// Input: arr = [1,2,3]
// Output: [1,2,3]
// Explanation: After calling your function, the input array is modified to: [1,2,3]

// Constraints:

// 1 <= arr.length <= 104
// 0 <= arr[i] <= 9

class Solution {
    public:
        void duplicateZeros(vector<int>& arr) {
            for(int i = 0; i < arr.size(); i++){
                if(arr.at(i) == 0){
                    for(int j = arr.size()-1; j > i+1; j--){
                        arr.at(j) = arr.at(j-1); 
                    }
                    if(i != arr.size() - 1)
                        arr.at(i+1) = 0;
                    i++;
                }
            }
        }
    };


class ONSolution {
    public:
        void duplicateZeros(vector<int>& arr){
            int length = arr.size() - 1;
            int possibleDups = 0;
            // Find the number of zeros to be duplicated
            // Stopping when left points beyond the last element in the original array
            // which would be part of the modified array
            for(int i = 0; i < length - possibleDups; i++){
                if(arr[i] == 0){
                    // Edge case: This zero can't be duplicated. We have no more space,
                    // as left is pointing to the last element which could be included  
                    if(i == length - possibleDups){
                        arr[length] = 0;
                        length--;
                        break;
                    }
                    possibleDups++;
                }
            }

            int last = length - possibleDups;

            // Copy zero twice, and non zero once.
            for(int i = last; i >= 0; i--){
                if(arr[i] == 0){
                    arr[i + possibleDups] = 0;
                    possibleDups--;
                    arr[i + possibleDups] = 0;
                }
                else{
                    arr[i + possibleDups] = arr[i];
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
    vector<int> a = {1,0,2,3,0,4,5,0};
    ONSolution s;
    s.duplicateZeros(a);
    printVector(a);
    return 0;
}