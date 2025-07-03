#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    auto it1 = numbers.begin();
    auto it2 = numbers.end() - 1;
    // this problem specify that index started from 0
    
    while (it1 < it2){
      int num = *it1 + *it2;
      if(num == target)
        return {int(it1-numbers.begin()),int(it2-numbers.begin())};
      
      if(num < target){
        it1++;
      }
      else{
        it2--;
      }
    }
    return {};
  }
};