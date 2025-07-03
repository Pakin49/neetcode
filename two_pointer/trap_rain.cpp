#include<iostream>
#include<vector>
using namespace std;

int min(int a,int b){
  return a<b? a : b;
}
void check(vector<int> prefix,vector<int> suffix, vector<int>area){
  cout << "Prefix : [ ";
  for(int i : prefix){
    cout << i << " ";
  }
  cout << "]" << endl;
  cout << "Suffix : [ ";
  for(int i : suffix){
    cout << i << " ";
  }
  cout << "]" << endl;
  cout << "Areas  : [ 0 ";
  for(int i : area){
    cout << i << " ";
  }
  cout << "0 ]" << endl;
}

class Solution {
public:
  int trap(vector<int>& height) {
    vector<int> prefix,suffix,areas;
    int area = 0;
    // skip the first and the last blocks
    int left = 0, right = height.size()-1;
    int max_left = height[0] , max_right = height[height.size()-1];

    for(int i = 0; i <height.size()-1; i++){
      if (i == 0){
        prefix.push_back(0);
        suffix.push_back(0); // first element pushback and insert samething
      }
      if (height[left]>max_left)  max_left = height[left];
      if (height[right]>max_right) max_right = height[right];
      prefix.push_back(max_left);
      suffix.insert(suffix.begin(),max_right);
      left++;
      right--;
    }
    for(int i=1;i<height.size()-1;i++){
      int water = min(prefix[i],suffix[i])-height[i];
      if (water<0){
        water = 0;
      }
      areas.push_back(water);
      area += water;
    }
    check(prefix,suffix,areas); 
    cout <<area<<endl;
    return area;
  }
};

int main(){
  vector<int> height = {4,2,0,3,2,5};
  cout << "Height : [ ";
  for (int i : height){
    cout << i << " ";
  }
  cout<< "]" << endl;
  Solution solution;
  solution.trap(height);
}