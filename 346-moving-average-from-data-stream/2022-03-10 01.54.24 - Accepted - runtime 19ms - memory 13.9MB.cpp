class MovingAverage {
    int *window;
    int n = 0;
    int cursor = 0;
    int size;
    double sum = 0.0;
public:
    MovingAverage(int size) {
        window = new int[size];
        this->size = size;
        memset(window,0.0,size*sizeof(int));
    }
    
    double next(int val) {
        n++;
        int div = min(size,n);
        sum+=(double)val;
        sum-=(double)window[cursor];
        window[cursor]=val;
        cursor++; cursor%=size;
        return sum/div;
        
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */