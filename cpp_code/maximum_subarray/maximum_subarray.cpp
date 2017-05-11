#include<iostream>
#include<vector>
#include<climits>

using namespace std;


class Solution{
public:
    int maxSubArray(vector<int>& nums){
        int running_max = INT_MIN, running_sum = 0;

        for(int i=0; i<nums.size(); i++){
            running_sum += nums[i]; // Running sum since last zero.
            running_max = max(running_sum, running_max); // Running maximum.
            running_sum = max(0, running_sum);
            }
        return running_max;
        }
    };



int main(void){
    Solution solution;
    int retVal;
    vector<int> nums;

    nums = {-2, 1, -3, 4, -1, 2, 1, -5, 5};
    retVal = solution.maxSubArray(nums);
    cout << "Max: " << retVal << endl;

    nums = {-3};
    retVal = solution.maxSubArray(nums);
    cout << "Max: " << retVal << endl;

    nums = {1};
    retVal = solution.maxSubArray(nums);
    cout << "Max: " << retVal << endl;

    nums = {1,-1,1,-1};
    retVal = solution.maxSubArray(nums);
    cout << "Max: " << retVal << endl;

    return 0;
    }
