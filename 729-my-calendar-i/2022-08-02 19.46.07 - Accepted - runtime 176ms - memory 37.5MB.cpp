class MyCalendar {
    vector<pair<int,int>> sched;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(!sched.empty()){
            for(auto [s,e]: sched)
                if(s < end && start < e) return false;
        }
        sched.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */