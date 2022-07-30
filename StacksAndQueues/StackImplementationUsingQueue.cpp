#include<bits/stdc++.h>
using namespace std;

// For interview, first start with 2 queues approach, then tell the 
// single queue approach. 

// For both the approachs TC = O(N), the only difference is SC = O(2*N) for 2 queues
// and SC = O(N) for single queue. 

// single Queue Approach : 
class MyStack {
public:
    int sz=0;
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0;i<sz;i++) {
            int y = q.front();
            q.pop();
            q.push(y);
        }
        sz++;
    }
    
    int pop() {
        int x= q.front();
        q.pop();
        sz--;
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(sz==0) return true;
        else return false;
    }
};