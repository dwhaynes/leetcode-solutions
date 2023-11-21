class Solution {
    map<string,int> wordCount;
    int wordLength;
    int substringSize;
    int k;
    
    bool check(int i, string s){
        map<string,int> remaining{wordCount};
        int wordsUsed = 0;
        for(int j = i; j < i + substringSize; j+=wordLength){
            string sub = s.substr(j,wordLength);
            if(remaining[sub] != 0){
                remaining[sub]--;
                wordsUsed++;
            }else break;
        }
        return wordsUsed == k;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        k = words.size();
        wordLength = words[0].size();
        substringSize = wordLength * k;
        
        for(string word: words){
            wordCount[word]++;
        }
        
        vector<int> answer;
        for(int i = 0; i < n-substringSize+1; i++){
            if(check(i,s)) answer.push_back(i);
        }
        return answer;
    }
};