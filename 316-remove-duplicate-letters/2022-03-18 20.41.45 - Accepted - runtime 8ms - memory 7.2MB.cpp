class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stack;
        set<char> seen;
        map<char,int> last_occurrence;
        for(int i = 0; i < s.size(); i++) last_occurrence[s[i]]=i;
        
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(seen.find(c) == seen.end()){
                while(!stack.empty() && c < stack.top() && last_occurrence[stack.top()] > i){
                    seen.erase(stack.top());
                    stack.pop();
                }
                seen.insert(c);
                stack.push(c);
            }
        }
        string ans = "";
        while(!stack.empty()){
            ans = stack.top() + ans;
            stack.pop();
        }
        return ans;
    }
};