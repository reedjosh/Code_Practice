// Joshua Reed
//
// Spring 2017
//
// Another LeetCode problem.
//
// Find the length of the last word in a string.
#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    int lengthOfLastWord(string s){
        int idx1 = 0, idx2 = 0;

        // Find the index of first non-whitespace (looking backword).
        idx1 = (s.length() > 0) ? s.length() : 0;
        while ((s[idx1-1] == ' ') && (idx1 > 0))
            idx1--;

        // Find the index of the next space in the string (looking backword).
        idx2 = idx1;
        while ((s[idx2-1] != ' ') && (idx2 > 0))
            idx2--;

        return idx1 - idx2;
        }
};

int main(void){
    Solution solution;

    string s = "Hello World. "; // Should return 
    int solVal = solution.lengthOfLastWord(s);
    cout << solVal << endl;

    s = "HelloWorld."; // Should return 11
    solVal = solution.lengthOfLastWord(s);
    cout << solVal << endl;

    s = ""; // Should return 0
    solVal = solution.lengthOfLastWord(s);
    cout << solVal << endl;

    s = "   "; // Should return 0
    solVal = solution.lengthOfLastWord(s);
    cout << solVal << endl;
    
    s = " a "; // Should return 1
    solVal = solution.lengthOfLastWord(s);
    cout << solVal << endl;
    
    s = "a"; // Should return 1
    solVal = solution.lengthOfLastWord(s);
    cout << solVal << endl;
   
     return 0;
    }



