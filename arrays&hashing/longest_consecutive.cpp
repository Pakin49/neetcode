#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set <int> num_set;// to make access time O(1)
      for(int n : nums) {num_set.insert(n);}

      int max = 0;
      for(int n : num_set){
        if(num_set.find(n-1) == num_set.end())
        {
          int current = 1;
          while(1){
            if (num_set.find(n+current) == num_set.end())
              break;
            current++;  
          }
          if(current>max) {max = current;}
        }
      }
      return max;
    } 
};