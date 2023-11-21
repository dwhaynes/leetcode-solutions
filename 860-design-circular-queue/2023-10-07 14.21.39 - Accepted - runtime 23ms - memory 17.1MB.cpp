class MyCircularQueue {
    vector<int> q;
    int cap;
    int count;
    int head;
public:
    MyCircularQueue(int k) {
        head = 0;
        cap = k;
        count = 0;
        q = vector<int>(k);
    }
    
    bool enQueue(int value) {
        if (count == cap) return false;
        q[(head + count) % cap] = value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if (count == 0) return false;
        head = (head + 1) % cap;
        count--;
        return true;
    }
    
    int Front() {
        if (count == 0) return -1;
        return q[head];
    }
    
    int Rear() {
        if (count == 0) return -1;
        int tail = (head + count - 1) % cap;
        return q[tail];
    }
    
    bool isEmpty() {
        return (count == 0);
    }
    
    bool isFull() {
        return (count == cap);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */