// Software Ripple Carry Adder



#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    vector<int> plusOne(vector<int>& digits){
        vector<int> sum;
        int carry = 1, total = 0;
    
        for (int i=0; i<digits.size(); i++){
            total = digits[digits.size()-i-1] + carry;
            sum.insert(sum.begin(), total % 10);
            carry = total / 10;
            }
        if (carry) sum.insert(sum.begin(), 1);
        return sum;
        }
    };


int main(void){
    Solution solution;
    vector<int> in_vec;
    in_vec = {9, 9, 9};
    vector<int> value = solution.plusOne(in_vec);
    cout << endl << "Returned: ";
    for (int i=0; i<value.size(); i++){
        cout << value[i];
        }
        
    }
