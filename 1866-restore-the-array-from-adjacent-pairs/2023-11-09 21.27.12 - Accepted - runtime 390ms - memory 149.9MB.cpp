class Solution {
    vector<int> ans;
    unordered_map<int,vector<int>> graph;

    void dfs(int start, int prev){
        ans.push_back(start);
        for(auto next: graph[start]){
            if(next != prev )dfs(next,start);
        }
    }
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        int start = INT_MAX;
        for(auto adjpair:adjacentPairs){
            graph[adjpair[0]].push_back(adjpair[1]);
            graph[adjpair[1]].push_back(adjpair[0]);
        }
        
        for(auto& [k,v]: graph){
            if(v.size() == 1){
                start = k;
                break;
            }
        }

        dfs(start,INT_MAX);
        return ans;
    }
};