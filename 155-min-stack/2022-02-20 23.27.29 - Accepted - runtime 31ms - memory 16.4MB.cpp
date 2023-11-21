class MinStack {
    stack<pair<int,int>> stack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (stack.empty()){
            stack.push({val,val});
            return;
        }
        int minval = this->getMin();
        stack.push({val,min(minval,val)});
    }
    
    void pop() {
        stack.pop();
    }
    
    int top() {
        return stack.top().first;
    }
    
    int getMin() {
        return stack.top().second;
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