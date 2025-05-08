#include<iostream>
#include<stack>

using namespace std;
class MinStack {
private:
  // 2 stacks, the first one just normal stack
  // another one store minimum until the current value
  stack<int> stk;
  stack<int> minstk;
public:
  MinStack() { }

  void push(int val) {
    if(stk.empty()){
      stk.push(val);
      minstk.push(val); 
    }
    else{
      stk.push(val);
      val = minstk.top()<val ? minstk.top():val;
      minstk.push(val);
    } 
  }

  void pop() {
    stk.pop();
    minstk.pop();
  }

  int top() {
    return stk.top();
  }

  int getMin() {
    return minstk.top(); 
  }
};
