class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> good(words.begin(),words.end());
        for(auto word: words){
            for(int k = 1; k < word.size(); k++) good.erase(word.substr(k));
        }
        int ans = 0;
        for(string word: good){
            ans+=word.size()+1;
        }
        return ans;
    }
};