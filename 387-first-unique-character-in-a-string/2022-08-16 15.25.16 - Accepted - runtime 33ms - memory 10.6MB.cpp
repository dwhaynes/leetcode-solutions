class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> seen(26,0);
        for(auto c:s) seen[c-'a']++;
        for(int i = 0; i < s.size(); i++){
            if(seen[s[i]-'a'] == 1) return i;
        }
        return -1;
    }
};