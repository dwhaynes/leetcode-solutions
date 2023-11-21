class Solution {
    vector<bool> seen;
    vector<set<int>> adj;
    bool bfs(int source, int destination){
        queue<int> q;
        seen[source] = true;
        for(auto node: adj[source]){
            if(node ==  destination) return true;
            q.push(node);
            seen[node] = true;
        }
        
        while(!q.empty()){
            auto node = q.front();
            if(node == destination) return true;
            q.pop();
            for(auto vertex: adj[node]){
                if(!seen[vertex]){
                    seen[vertex] = true;
                    q.push(vertex);
                }
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination || n == 1 || edges.empty()) return true;
        seen = vector<bool>(n,false);
        adj = vector<set<int>>(n,set<int>());
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        return bfs(source,destination);
    }
};