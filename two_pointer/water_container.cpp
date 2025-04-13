#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& heights) {
      // one pointer @begining, another @end
      int left = 0, right = heights.size() - 1;
    
      int max = 0, area = 0;
      vector <int> index;
      while(left < right){
        area = min(heights[left],heights[right]) * (right-left);
        if (area > max){
          max = area;
        }
        if (heights[left] < heights[right]) {
          left++;
        }
        else{
          right--;
        }
      }
      return max;
    }
};

int min( int a, int b){
  return a < b? a : b;
}

int main(){
  Solution solution;
  vector <int> heights = {1,7,2,5,12,3,500,500,7,8,4,7,3,6};
  int ans = solution.maxArea(heights);
  cout << ans <<endl;
}