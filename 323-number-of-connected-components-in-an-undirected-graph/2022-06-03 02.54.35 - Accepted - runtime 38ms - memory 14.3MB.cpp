class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> seen(n,false);
        vector<vector<int>> graph(n,vector<int>());
        
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int ctr = 0;
        for(int a = 0; a < n; a++){
            if(!seen[a]){
                ctr++;
                stack<int> stack;
                stack.push(a);
                seen[a] = true;
                
                while(!stack.empty()){
                    int node = stack.top();
                    stack.pop();
                    for(auto next: graph[node]){
                        if(seen[next]) continue;
                        seen[next] = true;
                        stack.push(next);
                    }
                }
            }
        }
        return ctr;
    }
};