class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stack;
        set<char> seen;
        unordered_map<char,int> last_occurence;

        for(int i = 0; i < s.size(); i++) last_occurence[s[i]]=i;

        for(int i = 0; i < s.size(); i++){
            auto c = s[i];

            if(!seen.contains(c)){
                while(!stack.empty() && c < stack.top() && last_occurence[stack.top()] > i){
                    seen.erase(stack.top());
                    stack.pop();
                }
                seen.insert(c);
                stack.push(c);
            }
        }

        stringstream ss;
        while(!stack.empty()){
            ss << stack.top();
            stack.pop();
        }
        auto ans = ss.str();
        return string(ans.rbegin(),ans.rend());

    }
};