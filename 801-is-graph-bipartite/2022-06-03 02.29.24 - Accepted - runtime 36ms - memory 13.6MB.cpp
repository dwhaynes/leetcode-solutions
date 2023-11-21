class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        
        for(int start = 0; start < n; ++start){
            if(color[start] == -1){
                stack<int> stack;
                stack.push(start);
                color[start]=0;
                
                while(!stack.empty()){
                    int node = stack.top();
                    stack.pop();
                    
                    for(int next: graph[node]){
                        if(color[next] == -1){
                            stack.push(next);
                            color[next] = color[node]^1;
                        }else if(color[next] == color[node]) return false;
                    }
                }
            }
        }
        return true;
    }
};