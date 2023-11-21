class Solution {
    bool isPalindrome(string s){
        int l = 0;
        int r = s.size()-1;
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
public:
    int removePalindromeSub(string s) {
        if(s.empty()) return 0;
        if(isPalindrome(s)) return 1;
        return 2;
    }
};