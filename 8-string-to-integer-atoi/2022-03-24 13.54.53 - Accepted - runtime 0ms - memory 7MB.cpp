class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        string clean = "";
        bool neg = false;
        int ans = 0;
        while(i < s.size() && s[i] == ' ') i++;
        if(i < s.size() && s[i] == '-'){
            neg = true;
            i++;
        }else if(i < s.size() && s[i] == '+'){
            i++;
        }
        while(isdigit(s[i])){
            clean+=s[i];
            i++;
        }
        for(i = 0; i < clean.size(); i++){
            int digit = clean[i] - '0';
            if( ans > INT_MAX/10 || (ans == INT_MAX/10 && digit > INT_MAX % 10)){
                return (neg) ? INT_MIN : INT_MAX;
            }
            ans *= 10;
            ans += digit;
        }
        return (neg) ? -ans : ans;
        
    }
};