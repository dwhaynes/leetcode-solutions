class Solution {
public:
    string removeDuplicateLetters(string s) {
        deque<char> stack;
        set<char> seen;
        map<char,int> last_occurrence;
        for(int i = 0; i < s.size(); i++) last_occurrence[s[i]]=i;
        
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(seen.find(c) == seen.end()){
                while(!stack.empty() && c < stack.back() && last_occurrence[stack.back()] > i){
                    seen.erase(stack.back());
                    stack.pop_back();
                }
                seen.insert(c);
                stack.push_back(c);
            }
        }
        
        return string(stack.begin(),stack.end());
    }
};