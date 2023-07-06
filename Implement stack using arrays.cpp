#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    vector<int> v;
    int vectorsize;
    Stack(int capacity) {
        // Write your code here.
        vectorsize = capacity;
    }

    void push(int num) {
        // Write your code here.
       v.push_back(num);
    }

    int pop() {
        // Write your code here.
        int ans = -1;
        if(!v.empty()){
         ans = v.back();
        v.pop_back();
        }
        return ans;
    }
    
    int top() {
        // Write your code here.
        int ans = -1;
        if(!v.empty()){
            ans = v.back();
        }
        return ans;
    }
    
    int isEmpty() {
        // Write your code here.
        if(v.size()==0) return 1;
        return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(v.size() == vectorsize) return 1;
        return 0;
    }
    
};