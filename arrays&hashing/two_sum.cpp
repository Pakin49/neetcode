#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; 
            for (int i = 0; i < nums.size(); i++) {
                int diff = target - nums[i]; 
                if (numMap.find(diff) != numMap.end()) {
                    return {numMap[diff], i};
                }
                numMap[nums[i]] = i;
            }
            return {}; 
        }
 };
    