#include<iostream>
#include<vector>
using namespace std;

void check(vector<int> prefix, vector<int> suffix){
  cout<< "prefix : [";
  for(int i=0; i<prefix.size();i++){
    cout<<prefix[i]<<" ";
  }
  cout<< ']'<<endl;
  cout<< "suffix : [";
  for(int i=0; i<suffix.size();i++){
    cout<<suffix[i]<<" ";
  }
  cout<< ']'<<endl;
}

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      vector<int> prefix,suffix,result;
      // initialize the first front and back elements
      auto it1 = nums.begin();
      auto it2 = nums.end()-1;
      int size = nums.size();
      int prod_prefix = 1;
      int prod_suffix = 1;
      prefix.push_back(1);
      suffix.insert(suffix.begin(),1);
      
      // loop though vector calculate the product from left&right put in prefix&suffix;
      for(int i = 0; i<size-1;i++){
        prod_prefix *= *it1; it1++;
        prod_suffix *= *it2; it2--;
        prefix.push_back(prod_prefix);
        suffix.insert(suffix.begin(),prod_suffix);
      }
      check(prefix,suffix);
      for(int i = 0; i<size; i++){
        result.push_back(prefix[i]*suffix[i]);
      }
      return result;
    }
};