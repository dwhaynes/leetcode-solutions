class Solution {
    stack<char> stack;
public:
    bool isValid(string s) {
        for(auto c: s){
            if (c == '(' || c == '[' || c == '{'){
                stack.push(c);
            }else{
                if (stack.empty()) return false;
                if (c == ')' && stack.top() == '(') stack.pop();
                else if (c == ']' && stack.top() == '[') stack.pop();
                else if (c == '}' && stack.top() == '{') stack.pop();
                else return false;
            }
        }
        return stack.size() == 0 ? true : false;
    }
};