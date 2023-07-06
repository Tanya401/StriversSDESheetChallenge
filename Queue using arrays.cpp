#include <bits/stdc++.h> 
class Queue {
public:
vector<int> v;
    Queue() {
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(v.size()==0) return true;
        return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        v.push_back(data);
    }

    int dequeue() {
        // Implement the dequeue() function
        if(v.size() == 0)return -1;
        int ans = v[0];
        for(int i=0;i<v.size()-1;i++){
            v[i] =v[i+1];
        }
        v.pop_back();
        return ans;
    }

    int front() {
        // Implement the front() function
        if(v.size()==0) return -1;
        return v[0];
    }
};