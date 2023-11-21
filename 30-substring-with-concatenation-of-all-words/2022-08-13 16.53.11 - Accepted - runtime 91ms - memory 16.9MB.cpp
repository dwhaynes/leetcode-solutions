class Solution {
    map<string,int> wordCount;
    int n;
    int k;
    int substringSize;
    int wordLength;
    
    void slidingWindow(int left, string& s, vector<int>& ans){
        map<string,int> wordsFound;
        int wordsUsed = 0;
        bool excessWord = false;
        
        for(int right = left; right <= n - wordLength; right+=wordLength){
            auto sub = s.substr(right,wordLength);
            if(wordCount.count(sub) == 0){
                wordsFound.clear();
                wordsUsed = 0;
                excessWord = false;
                left = right+wordLength;
            }else{
                while(right - left == substringSize || excessWord){
                    auto leftmostWord = s.substr(left,wordLength);
                    left+=wordLength;
                    wordsFound[leftmostWord]--;
                    
                    if(wordsFound[leftmostWord] >= wordCount[leftmostWord]) excessWord = false;
                    else wordsUsed--;
                }
                
                wordsFound[sub]++;
                if(wordsFound[sub] <= wordCount[sub]) wordsUsed++;
                else excessWord = true;
                if(wordsUsed == k && !excessWord) ans.push_back(left);
            }
        }
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        n = s.size();
        k = words.size();
        wordLength = words[0].size();
        substringSize = k*wordLength;
        
        for(auto word: words){
            wordCount[word]++;
        }
        vector<int> ans;
        for(int i = 0; i < wordLength;i++){
            slidingWindow(i,s,ans);
        }
        return ans;
    }
};