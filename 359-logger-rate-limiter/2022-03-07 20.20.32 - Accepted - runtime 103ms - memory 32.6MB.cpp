class Logger {
    map<string,int> timer;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        int time;
        if(timer.find(message) != timer.end()) time = timer[message];
        else time = 0;
        if(time <= timestamp){
            timer[message] = timestamp + 10;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */