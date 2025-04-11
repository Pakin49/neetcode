#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
  public:
      vector<vector<int>> threeSum(vector<int>& nums) {
          sort(nums.begin(),nums.end());
          vector <vector<int>> output;

          for (int i = 0; i < nums.size(); i++){
            if(i!=0 && nums[i] == nums[i-1]){
              continue; // skip the duplicate
            }
            int left = i+1, right = nums.size()-1;
            while (left < right){

              // core algorithm
              int sum = nums[i]+nums[left]+nums[right];
              if(sum == 0){
                output.push_back({nums[i],nums[left],nums[right]});
                left++;
                right--;    
                while(left<right && nums[left] == nums[left-1])   {left++;}
                while(left<right && nums[right] == nums[right+1]) {right--;}
            
              }

              else if(sum < 0){
                left++;
              }
              else{
                right--;
              }
            }
          }
          return output;
      }
  };

  int main() {
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = solution.threeSum(nums);

    for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}