class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while(columnNumber){
            columnNumber--;
            char digit = columnNumber %26 + 'A';
            ans += digit;
            columnNumber/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};