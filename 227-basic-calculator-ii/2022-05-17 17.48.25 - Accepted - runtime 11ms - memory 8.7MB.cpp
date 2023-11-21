class Solution {
public:
    int calculate(string s) {
        if(s.empty()) return 0;
        int len = s.size();
        stack<int> stack;
        int currentNumber = 0;
        char operation = '+';
        for(int i = 0; i < len; i++){
            char currentChar = s[i];
            if(isdigit(currentChar)) currentNumber = (currentNumber * 10) + (currentChar - '0');
            if(!isdigit(currentChar) && !isspace(currentChar) || i == len - 1){
                if(operation == '-') stack.push(-currentNumber);
                else if(operation == '+') stack.push(currentNumber);
                else if(operation == '*') {
                    int temp = stack.top() * currentNumber;
                    stack.pop();
                    stack.push(temp);
                }
                else if(operation == '/'){
                    int temp = stack.top() / currentNumber;
                    stack.pop();
                    stack.push(temp);
                }
                operation = currentChar;
                currentNumber = 0;
            }
        }
        int ans = 0;
        while(!stack.empty()){
            ans+=stack.top();
            stack.pop();
        }
        return ans;
    }
};