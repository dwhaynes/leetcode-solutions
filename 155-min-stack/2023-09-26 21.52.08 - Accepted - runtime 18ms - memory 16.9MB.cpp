class MinStack {
    stack<int> s,m;
public:
    MinStack() {
    
    }
    
    void push(int val) {
        s.push(val);
        m.push(m.empty() ? val : min(val,m.top()));
    }
    
    void pop() {
        s.pop();
        m.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return m.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */