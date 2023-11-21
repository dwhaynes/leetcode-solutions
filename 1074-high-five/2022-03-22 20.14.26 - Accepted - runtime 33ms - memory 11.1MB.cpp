class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int,priority_queue<int>> scores;
        vector<vector<int>> results;
        for(auto kv: items) scores[kv[0]].push(kv[1]);
        for(auto& kv: scores){
            int score = 0;
            for(int i = 0; i < 5; i++){
                score+=kv.second.top();
                kv.second.pop();
            }
            results.push_back({kv.first,score/5});
        }
        return results;
    }
};