#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s){
      if (s.size() < 2)
        return false;
      stack <char> parentheses;
      for(char c : s){
          switch(c) {
          case '[':
            parentheses.push(c);
            break;
          case '(':
            parentheses.push(c);
            break;
          case '{':
            parentheses.push(c);
            break;
          case ']':
            if (parentheses.empty() || parentheses.top() != '[')
              return false;
            parentheses.pop();
            break;
          case ')':
            if (parentheses.size()==0 || parentheses.top() != '(')
              return false;
            parentheses.pop();
            break;
          case '}':
            if (parentheses.size()==0 || parentheses.top() != '{')
              return false;
            parentheses.pop();
            break;
          default:
            cerr<<"invailid input"<<endl;
        }
      }
      if (parentheses.empty())
        return true;
      return false;  
    }       
};           
