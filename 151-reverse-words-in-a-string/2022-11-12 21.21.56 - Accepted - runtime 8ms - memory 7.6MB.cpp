class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.size()-1;
        while(left <= right && s[left] == ' ') left++;
        while(left <= right && s[right] == ' ') right--;
        string word = "";
        stack<string> stack;

        while(left <= right){
            char c = s[left];
            if(c == ' ' && word.size() != 0){
                stack.push(word);
                word = "";
            }else if(c != ' '){
                word += c;
            }
            left++;
        }
        string ans = word;
        while(!stack.empty()){
            ans += (" " + stack.top());
            stack.pop();
        }
        return ans;
    }
};