// Joshua Reed
// Practice Problem
// Sprint, 2017
//
// Within a given vector, find the two numbers that sum to the targeted number.
//
// I found this problem on the leetcode website. 
//
// The original problem assumes that there will always be exactly one solution.
//
// My approach here is to iteratively check and hash (to map) each number in the nums vector. 
// Each iteration, a number's index and key is stored until a complementing number
// is found in the map.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> map; // Map to hash found nums.

    for (int i=0; i<nums.size(); i++)
        // Check if this number's complement has been previously found.
        if (map.find(target-nums[i]) != map.end()) 
            return {map[target-nums[i]], i}; // Return solution.
        else 
            map.emplace(nums[i], i); // Store the number
        }


int main(void){
    // Could use more and better test cases!

    vector<int> nums = {-0, 1, 5, 4}; // Test vector.

    vector<int> result = twoSum(nums, 4); // Get results
 
    cout << "Index 1: " << result[0] << endl <<  "Index 2: " << result[1]; // Print results.

    return 0;
    }

