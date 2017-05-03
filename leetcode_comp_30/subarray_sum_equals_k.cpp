#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//class Solution{
//public:
//    int subarraySum(vector<int>& nums, int k){
//        unordered_map<int, int> map;
//        int subArrs = 0, curr = 0, needed = 0;
//
//        for (int i = 0; i < nums.size(); i++){  
//            curr = nums[i];
//            needed = k-curr;
//            // If the complement to the current number can be found in a previous subarray.
//            if (map.find(needed) != map.end())
//                subArrs += map[needed];
//            if (map.find(nums[i]) == map.end()) // Number not found yet.
//                unordered_map.emplace(curr, 1)
//            else // Increment the number of ways this number can be created.
//                map[nums[i]]++;
//            
//            }
//        
//        
//        return 0;
//        }
//    };

//class Solution{
//public:
//// Function to print subarray with sum as given sum
//int subarraySum(vector<int> arr, int sum)
//{
//    // create an empty map
//    unordered_map<int, int> map;
// 
//    // Maintains sum of elements so far
//    int curr_sum = 0;
// 
//    for (int i = 0; i < arr.size(); i++)
//    {
//        // add current element to curr_sum
//        curr_sum = curr_sum + arr[i];
// 
//        // if curr_sum is equal to target sum
//        // we found a subarray starting from index 0
//        // and ending at index i
//        if (curr_sum == sum)
//        {
//            cout << "Sum found between indexes "
//                 << 0 << " to " << i << endl;
//            return 0;
//        }
// 
//        // If curr_sum - sum already exists in map
//        // we have found a subarray with target sum
//        if (map.find(curr_sum - sum) != map.end())
//        {
//        }
//
// 
//        map[curr_sum] = i;
//    }
// 
//    // If we reach here, then no subarray exists
//    cout << "No subarray with given sum exists";
//    return 0;
//}
//};


typedef long long int64;
class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        int n = a.size();
        vector<int64> sum(n + 1);

        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + a[i];
            cout << sum[i] << " ";
        }

        unordered_map<int64, int> A;
        A[0] = 1;
        int ret = 0;
        cout << endl;
        for (int i = 1; i <= n; ++i) {
            ret += A[sum[i] - k];
            cout << A[sum[i] -k] << " ";
            A[sum[i]]++;
        }
        return ret;
        
    }
};



int main(void){
    Solution solution;

    vector<int> nums {18, -4, 8, 6} ;

    int num = solution.subarraySum(nums, 4);
    cout << endl << num << " ";

    
    }
