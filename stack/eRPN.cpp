#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<int> stk;
    int result = 0;
    for(int i=0; i<tokens.size();i++){

      bool isNumber = true, neg = false;
      string s = tokens[i];

      for(int i = 0; i<s.size();i++){
        if (s[0]=='-' && s.size()!= 1){
          neg = true;
          continue;
        }
        else if(!isdigit(s[i]))
          isNumber=false;
      }

      if(isNumber){
        int num = neg? stoi(s.substr(1)) * (-1) : stoi(s);
        stk.push(num);
        //cout<<"push : "<<tokens[i]<<endl;
      }
      else{

        int a,b;
        a = stk.top(); stk.pop();
        b = stk.top(); stk.pop();
        string s = tokens[i];
        if(!s.compare("+"))
          result = b + a;
        else if(!s.compare("-"))
          result = b - a;
        else if(!s.compare("*"))
          result = b * a;
        else if(!s.compare("/"))
          result = b / a;
        else {
          cout<< "Wrong notations :"<<s<<endl;
          return -1;
        }
        stk.push(result);
      }
      cout<< "result : "<< result << endl;
    }
    return stk.top();
  }
};