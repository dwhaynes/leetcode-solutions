class MyCalendarThree {
    unordered_map<int,int> vals, lazy;
    void update(int start, int end, int left, int right, int index){
        if(start > right || end < left) return;
        if(left >= start && right <= end){
            lazy[index]++;
            vals[index]++;
        }else{
            int mid = left + (right-left)/2;
            update(start,end,left,mid,2*index);
            update(start,end,mid+1,right,2*index+1);
            vals[index] = lazy[index] + max(vals[2*index],vals[2*index+1]);
        }
    }
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        update(start,end-1,1,1000000000,1);
        return vals[1];
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */