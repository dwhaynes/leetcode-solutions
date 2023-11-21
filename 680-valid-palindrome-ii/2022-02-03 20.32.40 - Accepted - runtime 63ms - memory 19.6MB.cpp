class Solution {
    bool isValid(string& s, int l, int r){
        while (l < r){
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int l=0;
        int r=s.size()-1;
        while(l < r){
            if(s[l] == s[r]){l++; r--; continue;}
            else{
                return isValid(s,l+1,r) || isValid(s,l,r-1);
            }
        }
        return true;
    }
};