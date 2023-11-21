class MovingAverage {
    deque<float> window;
    int size;
public:
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        window.push_back((float)val);
        while(window.size() > size) window.pop_front();
        return accumulate(window.begin(),window.end(),0.0)/window.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */