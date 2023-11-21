class MedianFinder {
    priority_queue<int,vector<int>,greater<int>> hi;
    priority_queue<int> lo;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        
        if(lo.size() < hi.size())
        {
            lo.push(hi.top());
            hi.pop();}
    }
    
    double findMedian() {
        if(lo.size() > hi.size()) return lo.top();
        return (lo.top() + hi.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */