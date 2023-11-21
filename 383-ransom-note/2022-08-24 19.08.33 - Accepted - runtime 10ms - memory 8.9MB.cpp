class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> r(26,0), m(26,0);
        for(auto ch: ransomNote) r[ch-'a']++;
        for(auto ch: magazine) m[ch-'a']++;
        for(int i = 0; i < 26; i++){
            if(r[i] > m[i]) return false;
        }
        return true;
    }
};