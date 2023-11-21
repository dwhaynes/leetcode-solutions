class Solution {
    string join(vector<string> words){
        int n = words.size();
        string out = words[0];
        for(int i = 1; i < n; i++){
            out += " ";
            out += words[i];
        }
        return out;
    }
    vector<string> split(string s){
        vector<string> out;
        
        int start = 0;
        int end = start;
        while(end < s.size()){
            while(end < s.size() && s[end] != ' ') end++;
            out.push_back(s.substr(start,end-start));
            end++;
            start = end;
        }
        return out;
    }
public:
    string reverseWords(string s) {
        vector<string> words;
        words = split(s);
        for(auto& word: words){
            reverse(word.begin(),word.end());
        }
        string ans = join(words);
        return ans;
    }
};