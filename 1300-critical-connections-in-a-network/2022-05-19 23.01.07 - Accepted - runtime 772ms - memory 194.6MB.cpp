class Solution {
    vector<vector<int>> graph, ans;
    vector<int> firstTime, minTime, visited;
    int time = 1;
    void dfs(int node, int parent = -1){
        firstTime[node] = minTime[node] = time++;
        visited[node] = true;
        
        for(auto child: graph[node]){
            if(child == parent) continue;
            
            if(!visited[child]) dfs(child,node);
            minTime[node] = min(minTime[node],minTime[child]);
            if(firstTime[node] < minTime[child]) ans.push_back({node,child});
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        firstTime.resize(n);
        minTime.resize(n);
        visited.resize(n);
        graph.resize(n);
        for(auto edge: connections){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        dfs(0);
        return ans;
    }
};