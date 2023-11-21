class Solution {
    deque<char> stack;
public:
    string removeDuplicates(string s) {
        for(auto c: s){
            if(!stack.empty() && stack.back() == c) stack.pop_back();
            else stack.push_back(c);
        }
        string res = "";
        while(!stack.empty()){
            res+=stack.front();
            stack.pop_front();
        }
        return res;
    }
};