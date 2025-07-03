#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures){
        stack<int> stk;
        vector<int> result;
        for(int i:temperatures)
            result.push_back(0);

        for(int i = 0; i<temperatures.size();i++){
            while(!stk.empty() && temperatures[i] > temperatures[stk.top()]){ 
                result[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        for(int i:result){
            cout<<result[i]<<" ";
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {30,38,30,36,40,28};
    solution.dailyTemperatures(temp);
}
