class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int dict[26];
        for(int i = 0; i < 26; i++) dict[order[i]-'a']=i;
        
        for(int i = 1; i < words.size(); i++){
            for(int j = 0; j < words[i-1].size(); j++){
                if(j >= words[i].size()) return false;
                if(words[i][j] != words[i-1][j]){
                    int curr = words[i-1][j]-'a';
                    int next = words[i][j]-'a';
                    if(dict[curr] > dict[next]) return false;
                    else break;
                }
            }
        }
        return true;
    }
};