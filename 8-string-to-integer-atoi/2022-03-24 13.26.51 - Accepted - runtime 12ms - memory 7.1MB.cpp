class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int i = 0;
        bool neg = false;
        string clean = "";
        while(s[i] == ' ') i++;
        if(s[i] == '-'){
            neg = true;
            i++;
        }else if (s[i] == '+'){
            i++;
        }
        while(isdigit(s[i])){
            clean+=s[i];
            i++;
        }
        for(i = 0; i < clean.size(); i++){
            ans*=10;
            ans+=(clean[i] - '0');
            if (ans > (long long) INT_MAX){
                if(neg) return INT_MIN;
                else return INT_MAX;
            }
        }
        if(neg) ans*=-1;
        if (ans > (long long) INT_MAX) return INT_MAX;
        else if (ans < (long long) INT_MIN) return INT_MIN;
        else return (int) ans;
    }
};