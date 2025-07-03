#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            int size = strs.size();
            unordered_map <string,vector<string>> sortedStringMap;
            for (string s : strs){
                string ss = s;
                sort(ss.begin(),ss.end());
                cout<<ss<<endl;
                sortedStringMap[ss].push_back(s);
            }
            vector<vector<string>> ans;
            for (auto &e : sortedStringMap){
                ans.push_back(e.second);
            }   
        return ans;
    }
};