class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n,vector<int>()), ret;
        vector<set<int>> ans(n,set<int>());
        queue<int> q;
        vector<int> indegree(n,0);
        for(auto edge: edges){
            indegree[edge[1]]++;
            graph[edge[0]].push_back(edge[1]);
        }
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto next: graph[node]){
                ans[next].insert(node);
                ans[next].insert(ans[node].begin(),ans[node].end());
                indegree[next]--;
                if(indegree[next] == 0) q.push(next);
            }
        }
        for(auto nodelist:ans) ret.push_back(vector(nodelist.begin(),nodelist.end()));
        return ret;
    }
};