class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> count;
        for(auto c: s) count[c]++;
        for(int i=0; i < s.size(); i++) if (count[s[i]] == 1) return i;
        return -1;
    }
};