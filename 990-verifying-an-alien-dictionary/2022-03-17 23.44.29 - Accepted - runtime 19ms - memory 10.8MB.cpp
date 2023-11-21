class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<string> translated, sorted;
        map<char,int> ord;
        int pos = 0;
        for(auto c: order) ord[c]=pos++;
        for(auto word: words){
            string temp;
            for(auto c: word) temp+=ord[c]+'a';
            translated.push_back(temp);
        }
        sorted = vector<string>(translated);
        sort(sorted.begin(),sorted.end());
        return sorted == translated;
    }
};