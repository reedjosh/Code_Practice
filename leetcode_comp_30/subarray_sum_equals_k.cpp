#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution{
public:
int subarraySum(vector<int>& nums, int k){
    map<int, int> a_map;
    int running_sum = 0, needed = 0, sub_arrs = 0;

    for (int i = 0; i <= nums.size(); i++){  
        needed = running_sum - k; // Amount to remove from running sum to equal k.
        sub_arrs += a_map[needed]; // Add ways needed can be made in previous arr.
        a_map[running_sum]++; // Add the running sum to the map.
        running_sum += nums[i]; // Manage running sum.
        }
    
    return sub_arrs;
    }
    };

void print_vec(vector<int> arr){
    int i;
    cout << '[';
    for (i=0; i < arr.size()-1; i++){  
        cout << arr[i] << ", ";
        }
    cout <<arr[i] << ']' << endl;
    }


void print_arr(int *arr, int size){
    int i;
    cout << '[';
    for (i=0; i < size-1; i++){  
        cout << arr[i] << ", ";
        }
    cout <<arr[i] << ']' << endl;
    }

int main(void){
    Solution solution;

    vector<int> nums {18, -4, 8, 6} ;

    int k = 4;
    cout << "k: " << k << endl;
    cout << "input vector: ";
    print_vec(nums);
    
    int num = solution.subarraySum(nums, k);
    cout << "return val: " << num << endl;
    cout << "should be:  1" << endl;

    nums  = {1,1,1} ;
    k = 2;

    cout << "k: " << k << endl;
    cout << "input vector: ";
    print_vec(nums);
    
    num = solution.subarraySum(nums, k);
    cout << "return val: " << num << endl;
    cout << "should be:  2" << endl;


    nums  = {-1,1,1,-2} ;
    k = -2;

    cout << "k: " << k << endl;
    cout << "input vector: ";
    print_vec(nums);
    
    num = solution.subarraySum(nums, k);
    cout << "return val: " << num << endl;
    cout << "should be:  1" << endl;


    nums  = {1} ;
    k = 0;

    cout << "k: " << k << endl;
    cout << "input vector: ";
    print_vec(nums);
    
    num = solution.subarraySum(nums, k);
    cout << "return val: " << num << endl;
    cout << "should be:  0" << endl;
    }
