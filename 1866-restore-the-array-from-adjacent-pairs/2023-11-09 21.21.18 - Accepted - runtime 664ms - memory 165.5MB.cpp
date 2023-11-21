class Solution {
    void dfs(int start,map<int,vector<int>>& graph, set<int>& seen, vector<int>& ans){
        if(seen.find(start) != seen.end()) return;
        seen.insert(start);
        ans.push_back(start);
        for(auto next: graph[start]){
            dfs(next, graph, seen, ans);
        }
    }
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> ans;
        map<int,vector<int>> graph;
        set<int> seen;
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

        dfs(start,graph,seen,ans);
        return ans;
    }
};