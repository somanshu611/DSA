#include<bits/stdc++.h>
using namespace std;

// For interview, first start with 2 stacks approach which is similar
// to 2 queue approach in stack implementation, then tell the 
// single stack approach. 

// SINGLE STACK APPROACH
// Time Complexity : 
// Push(x) : O(1)
// Pop(),Top() : Ammortised O(1), in worst case O(N)


class MyQueue {
public:
    stack<int> ip,op;
    int sz = 0;
    MyQueue() {
        
    }
    
    void push(int x) {
        ip.push(x);
        sz++;;
    }
    
    int pop() {
        if(sz==0) return -1;
        int x=peek();
        op.pop();
        sz--;
        return x;
    }
    
    int peek() {
        if(sz==0) return -1;
        if(!op.empty()) return op.top();
        else {
            while(!ip.empty()) {
                int x = ip.top();
                ip.pop();
                op.push(x);
            }
            return op.top();
        }
    }
    
    bool empty() {
        return sz==0 ? true : false;
    }
};


