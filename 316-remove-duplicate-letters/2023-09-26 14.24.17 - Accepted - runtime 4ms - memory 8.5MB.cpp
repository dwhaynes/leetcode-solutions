class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s == "") return s;
        vector<int> hist(26);
        for(auto c: s) hist[c-'a']++;
        int pos = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] < s[pos]) pos = i;
            if(--hist[s[i]-'a'] == 0) break;
        }
        string tail = s.substr(pos+1);
        auto rem = remove_if(tail.begin(),tail.end(),[&s,&pos](auto c){return c == s[pos];});
        tail.erase(rem,tail.end());
        return s[pos] + removeDuplicateLetters(tail);
    }
};