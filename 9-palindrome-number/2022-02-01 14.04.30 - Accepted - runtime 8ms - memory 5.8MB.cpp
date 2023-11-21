class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 ) return false;
        string chars = "";
        while(x){
            chars += (x%10);
            x /= 10;
        }
        int r = chars.size()-1;
        int l = 0;
        while(l < r){
            if(chars[l] != chars[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};