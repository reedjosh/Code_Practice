#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> vec){
    int i;
    cout << "[";
    for (i=0; i<vec.size()-1; i++)
        cout << vec[i] << ", ";
    cout << vec[i] << "]" << endl;
    }

class Solution{
public:
    int findUnsortedSubarray(vector<int>& nums){
        int idx1 = 0, idx2 = nums.size()-1;
        vector<int> nums2 = nums;
        sort(nums2.begin(), nums2.end());
        while((nums[idx1] == nums2[idx1]))
            idx1++;
        while(nums[idx2] == nums2[idx2])
            idx2--;

        return max(idx2-idx1+1, 0);
        }
    };

int main(void){
    Solution solution;
    vector <int> inVec;
    int retVal;

    cout << endl << "*********** Test Case 1 *************" << endl;
    inVec = {2, 6, 4, 8, 10, 9, 15};
    print(inVec);
    retVal = solution.findUnsortedSubarray(inVec);
    cout << "RetVal: " << retVal << endl;
    cout         << "*************************************" << endl;

    cout << endl << "*********** Test Case 2 *************" << endl;
    inVec = {5,1};
    print(inVec);
    retVal = solution.findUnsortedSubarray(inVec);
    cout << "RetVal: " << retVal << endl;
    cout         << "*************************************" << endl;

    cout << endl << "*********** Test Case 3 *************" << endl;
    inVec = {5,1,1,2};
    print(inVec);
    retVal = solution.findUnsortedSubarray(inVec);
    cout << "RetVal: " << retVal << endl;
    cout         << "*************************************" << endl;

    cout << endl << "*********** Test Case 4 *************" << endl;
    inVec = {1,1,2};
    print(inVec);
    retVal = solution.findUnsortedSubarray(inVec);
    cout << "RetVal: " << retVal << endl;
    cout         << "*************************************" << endl;
    }
