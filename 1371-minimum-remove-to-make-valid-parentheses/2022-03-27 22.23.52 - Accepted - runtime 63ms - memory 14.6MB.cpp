class Solution {
    string removeInvalidClosing(string s, char open, char close){
        stringstream ss;
        int balance = 0;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if (c == open) balance++;
            if (c == close){
                if (balance == 0) continue;
                balance--;
            }
            ss << c;
        }
        return ss.str();
    }
public:
    string minRemoveToMakeValid(string s) {
        string result = removeInvalidClosing(s,'(',')');
        reverse(result.begin(),result.end());
        result = removeInvalidClosing(result,')','(');
        reverse(result.begin(),result.end());
        return result;
    }
};