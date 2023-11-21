class Solution {
    stack<char> stack;
public:
    bool isValid(string s) {
        if(s == "") return true;
        for(auto ch: s){
            if(ch == '(' || ch == '[' || ch == '{'){
                stack.push(ch);
                continue;
            }
            if(ch == ')' && !stack.empty() && stack.top() == '('){
                stack.pop();
                continue;
            } else if(ch == ']' && !stack.empty() && stack.top() == '['){
                stack.pop();
                continue;
            } else if(ch == '}' && !stack.empty() && stack.top() == '{'){
                stack.pop();
                continue;
            } else return false;
        }

        return stack.size() > 0 ? false : true;
    }
};