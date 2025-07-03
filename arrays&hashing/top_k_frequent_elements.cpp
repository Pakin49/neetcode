#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool compare(const pair<int,int> &p1, const pair<int,int> &p2){
  return p1.second < p2.second; // ascending order
}

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> numMap;
    for(int i : nums)
      numMap[i]++;

    vector<pair<int,int>> vec;
    for(auto &entry : numMap){
      vec.push_back(entry);
    }
    sort(vec.begin(),vec.end(),compare);
    
    vector<int> ans;
    for (int i=0; i<k; i++){
      ans.push_back(vec.back().first);
      vec.pop_back();
    }
    return ans;
  }
};
