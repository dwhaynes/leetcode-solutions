class Solution {
    using dtype = pair<string,int>;
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        auto heads = vector<vector<dtype>>(26,vector<dtype>());
        
        for(auto word: words) heads[word[0]-'a'].push_back({word,0});
        
        for(auto c: s){
            vector<dtype> old = heads[c-'a'];
            heads[c-'a'] = {};
            
            for(auto node: old){
                node.second++;
                if(node.second == node.first.size()) ans++;
                else heads[node.first[node.second]-'a'].push_back(node);
            }
            old = {};
        }
        return ans;
    }
};