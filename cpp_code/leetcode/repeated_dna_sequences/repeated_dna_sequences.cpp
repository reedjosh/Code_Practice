#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<string> findRepeatedDnaSequences(string s){
        vector<string> sequences;
        unordered_map<string, int> map;
        string subString;

        if (s.length() < 10)
            return sequences;

        for (int i = 0; i < s.length()-9; i++){
            subString = s.substr(i, 10); 
            if (map.find(subString) != map.end()){
                if (map[subString] == 1)
                    sequences.push_back(subString);
                map[subString]++;
                }
            else
                map.emplace(subString, 1);
            }
        
        return sequences;
        }
    };

int main(void){
    string s = "abcdefghijkabcdefghijk";
    vector<string> sequences;

    Solution solution;
    sequences = solution.findRepeatedDnaSequences(s);
    for (vector<string>::iterator it = sequences.begin(); it != sequences.end(); it++)
        cout << *it << endl;
    }
