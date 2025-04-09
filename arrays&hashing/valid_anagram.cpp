#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;
class Solution{
public:
    bool isAnagram(string s, string t){
        if (s.length() != t.length())
            return false;
        
        unordered_map <char,int> ms,mt;
        for (char c : s)
            ms[c]++;
        for (char c : t)
            mt[c]++;
        return ms == mt;
    }
};