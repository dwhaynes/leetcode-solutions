class Solution {
    vector<string> split(string& s){
        vector<string> out;
        int last = 0, it = 0;
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
        for(auto dir: components){
            if(dir == "." || dir.empty()) continue;
            else if(dir == ".."){
                if(!dq.empty()) dq.pop_back();
            }
            else dq.push_back(dir);
        }
        string result;
        for(auto dir: dq) result+="/"+dir;
        return result.empty() ? "/" : result;
    }
};