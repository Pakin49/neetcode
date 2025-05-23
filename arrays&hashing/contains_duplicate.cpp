#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
  public:
      bool hasDuplicate(vector<int>& nums) {
          std::unordered_set<int> seen ;
          for(int num : nums){
              if(seen.count(num)){
                  return true;
              }
              seen.insert(num);
          }
          return false;
      }
  };