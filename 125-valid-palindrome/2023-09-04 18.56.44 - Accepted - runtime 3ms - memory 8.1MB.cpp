class Solution {
public:
    bool isPalindrome(string s) {
        stringstream filter;
        for(auto ch: s){
            if(isalnum(ch)) filter << char(tolower(ch));
        }
        string filtered = filter.str();
        int l = 0, r = filtered.size()-1;
        while(l <= r){
            if(filtered[l] != filtered[r]) return false;
            l++; r--;
        }
        return true;
    }
};