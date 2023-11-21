class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int end = start;
        int n = s.size();
        while(end < n){
            while(end < n && s[end] != ' ') end++;
            reverse(s.begin()+start,s.begin()+end);
            end++;
            start = end;
        }
        return s;
    }
};