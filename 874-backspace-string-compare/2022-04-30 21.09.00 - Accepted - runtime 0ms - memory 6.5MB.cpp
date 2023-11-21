class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss, st;
        for(auto c: s){
            if(c == '#'){
                if(ss.size() != 0) ss.pop();
            }
            else ss.push(c);
        }
        for(auto c: t){
            if(c == '#'){
                if(st.size() != 0) st.pop();
            }
            else st.push(c);
        }
        return ss == st;
    }
};