class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int L = beginWord.size();
        map<string,vector<string>> allComboDict;
        
        for(auto word: wordList){
            for(int i = 0; i < L; i++){
                string newWord = word.substr(0,i) + "*" + word.substr(i+1);
                allComboDict[newWord].push_back(word);
            }
        }
        
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        map<string,bool> visited;
        visited[beginWord] = true;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            auto word = node.first;
            auto level = node.second;
            
            for(int i = 0; i < L; i++){
                string newWord = word.substr(0,i) + "*" + word.substr(i+1);
                for(auto adj: allComboDict[newWord]){
                    if(adj == endWord) return level+1;
                    
                    if(!visited[adj]){
                        visited[adj] = true;
                        q.push({adj,level+1});
                    }
                }
            }
        }
        return 0;
    }
};