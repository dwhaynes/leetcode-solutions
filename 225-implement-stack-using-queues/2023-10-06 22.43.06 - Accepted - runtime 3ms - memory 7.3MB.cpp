class MyStack {
    queue<int> q1, q2;
    int topnum;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        topnum = x;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        int temp = topnum;
        q1.pop();
        if(!q1.empty()) topnum = q1.front();
        return temp;
    }
    
    int top() {
        return topnum;
    }
    
    bool empty() {
       return q1.empty(); 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */