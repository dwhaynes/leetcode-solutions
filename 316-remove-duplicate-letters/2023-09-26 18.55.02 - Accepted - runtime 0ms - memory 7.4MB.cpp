class Solution {
public:
    string removeDuplicateLetters(string s) {
        set<char> seen;
        map<char,int> last;
        deque<char> stack;

        for(int i = 0; i < s.size(); i++) last[s[i]]=i;

        for(int i = 0; i < s.size(); i++){
            auto c = s[i];
            if(!seen.contains(c)){
                while(!stack.empty() && c < stack.back() && last[stack.back()] > i){
                    seen.erase(stack.back());
                    stack.pop_back();
                }
                seen.insert(s[i]);
                stack.push_back(s[i]);

            }
        }
        return string(stack.begin(),stack.end());
    }
};