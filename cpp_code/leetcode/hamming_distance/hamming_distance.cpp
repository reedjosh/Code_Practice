#include <iostream>

using namespace std;


class Solution{
public:
    int hammingDistance(int x, int y){
        int ham = 0;
        while (x || y){
            if (x%2 != y%2) ham++;
            x /= 2;
            y /= 2;
            }
        return ham;
        }
    };



int main(void){
    Solution solution;
    int result = 0;
    result = solution.hammingDistance(8, 3);

    cout << "Run 1" << endl;
    cout << result << endl;
    
    }
