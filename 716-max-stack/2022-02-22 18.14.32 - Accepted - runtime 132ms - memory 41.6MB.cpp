class MaxStack {
    stack<int> _stack;
    stack<int> maxStack;
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        int max = maxStack.empty() ? x : maxStack.top();
        maxStack.push(max > x ? max : x);
        _stack.push(x);
    }
    
    int pop() {
        int num = top();
        _stack.pop();
        maxStack.pop();
        return num;
    }
    
    int top() {
        return _stack.top();
    }
    
    int peekMax() {
        return maxStack.top();
    }
    
    int popMax() {
        int max = peekMax();
        stack<int> buffer;
        while(top() != max) buffer.push(pop());
        pop();
        while(!buffer.empty()){
            push(buffer.top());
            buffer.pop();
        }
        return max;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */