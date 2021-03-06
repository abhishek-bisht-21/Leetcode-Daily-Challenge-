// 225. Implement Stack using Queues

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    queue<int>q1;
    queue<int>q2;
    
    /** Push element x onto stack. */
    void push(int x) {
        q2.push(x);
        
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        
        swap(q1,q2);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int result = top();
        q1.pop();
        return result;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};
