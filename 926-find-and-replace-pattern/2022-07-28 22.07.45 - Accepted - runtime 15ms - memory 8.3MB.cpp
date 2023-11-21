class Solution {
    bool match(string word, string pattern){
        map<char,char> M;
        for(int i = 0; i < word.size(); i++){
            auto w = word[i];
            auto p = pattern[i];
            if (M.count(w) == 0) M[w]=p;
            if (M[w] != p) return false;
        }
        vector<bool> seen(26,false);
        for(auto [w,p]: M){
            if (seen[p-'a']) return false;
            seen[p-'a'] = true;
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto word: words)
            if(match(word,pattern)) ans.push_back(word);
        return ans;
    }
};