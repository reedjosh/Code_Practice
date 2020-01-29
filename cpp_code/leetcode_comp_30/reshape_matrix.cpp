#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:

    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.size()*nums[0].size() != r*c) // Check number of inputs.
            return nums;
        else{
            vector<vector<int>> newMatrix(r, vector<int>(c));
            int col = 0, row = 0, counter = 0;

            for (int i = 0; i < nums.size(); i++){ // Rows...
                for (int j = 0; j < nums[i].size(); j++){ // Cols...
                    row = counter/c;
                    col = counter%c;
                    newMatrix[row][col] = nums[i][j];  // Re-assign.
                    counter ++;
                    }
                }
            return newMatrix;
            }
        }
    };



int main(void){
    Solution solution;

    vector<vector<int>> nums { {1,2},
                               {3,4}, {5,6} };

    nums = solution.matrixReshape(nums, 2, 3);
    for (int i = 0; i < nums.size(); i++){
        for (int j = 0; j < nums[i].size(); j++){
            cout << nums[i][j] << " ";
            }
        cout << endl;
        }

    
    }
