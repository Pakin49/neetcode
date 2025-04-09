#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
  public:
      string encode(vector<string>& strs) {
        string result = "";
          for(string s : strs){
            string size = to_string(s.size());
            result += size+'#'+s;
          }
          result += '\n';
          return result;
      }

      vector<string> decode(string s) {
        char* ptr = &s[0];
        vector <string> result;
        while(*ptr != '\n'){
          string string_size = "";
          while(*ptr!= '#'){
            string_size += *ptr;
            ptr++;
          }
          int lenght =  stoi(string_size); // convert char back to int
          string s = "";
          ptr++;  
          for(int i = 0; i<lenght; i++){
            s += *ptr;
            ptr++;
          }
          result.push_back(s);
        }
        return result;
      }
  };