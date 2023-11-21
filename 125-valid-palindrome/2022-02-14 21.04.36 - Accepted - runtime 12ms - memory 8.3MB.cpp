class Solution {
public:
    bool isPalindrome(string s) {
        stringstream filtered;
        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])) filtered << char(tolower(s[i]));
        }
        
        string test = filtered.str();
        int l = 0, r = test.size()-1;
        while(l <= r){
            if(test[l] != test[r]) return false;
            l++; r--;
        }
        return true;
    }
};