class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<int> pos1;
        vector<int> pos2;
        for(int i = 0; i < wordsDict.size(); i++){
            if(wordsDict[i] == word1) pos1.push_back(i);
            if(wordsDict[i] == word2) pos2.push_back(i);
        }
        int minDist = INT_MAX;
        for(int i = 0; i < pos1.size(); i++){
            for(int j = 0; j < pos2.size(); j++){
                int dist = abs(pos1[i]-pos2[j]);
                if (dist < minDist) minDist = dist;
            }
        }
        return minDist;
    }
};