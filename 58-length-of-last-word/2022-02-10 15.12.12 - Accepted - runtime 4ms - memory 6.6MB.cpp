class Solution {
public:
    int lengthOfLastWord(string s) {
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