class Solution {
    vector<string> split(string& s){
        vector<string> out;
        int it = 0;
        int last = 0;
        while(it < s.size()){
            while(it < s.size() && s[it] != '/') it++;
            out.push_back(s.substr(last,it-last));
            it++;
            last = it;
        }
        return out;
    }
public:
    string simplifyPath(string path) {
        deque<string> dq;
        auto components = split(path);
        
        for(auto directory: components){
            if(directory == "." || directory.empty()) continue;
            else if(directory == ".."){
                if(!dq.empty()) dq.pop_back();
            }else{
                dq.push_back(directory);
            }
        }
        string result;
        for(auto dir:dq){
            result+="/"+dir;
        }
        return result.size() > 0 ? result : "/";
    }
};