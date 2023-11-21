class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n,vector<int>());
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        map<int,int> parent;
        parent[0] = -1;
        stack<int> stack;
        stack.push(0);
        
        while(!stack.empty()){
            int node = stack.top();
            stack.pop();
            
            for(auto next: adj[node]){
                if(parent[node] == next) continue;
                if(parent.find(next) != parent.end()) return false;
                stack.push(next);
                parent[next]=node;
            }
        }
        return parent.size()==n;
    }
};