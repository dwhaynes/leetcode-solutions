class WordDistance {
    map<string,vector<int>> dists;
public:
    WordDistance(vector<string>& wordsDict) {
        for(int i = 0; i < wordsDict.size(); i++){
            dists[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int minDist = INT_MAX;
        for(auto d1: dists[word1]){
            for(auto d2: dists[word2]){
                if(abs(d1-d2) < minDist) minDist = abs(d1-d2);
            }
        }
        return minDist;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */