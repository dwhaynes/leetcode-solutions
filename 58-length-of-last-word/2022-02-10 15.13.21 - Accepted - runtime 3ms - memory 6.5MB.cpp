class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;
        int n = s.size();
        n--;
        int i;
        while(s[n] == ' ') n--;
        for(i = n; i >= 0; i--){
            if(s[i] == ' ') break;
        }
        return (n-i);
    }
};