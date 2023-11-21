class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        constexpr int sz = 26;
        vector<vector<int>> graph(sz);
        vector<int> color(sz,-1);
        
        for(string& eqn: equations){
            if(eqn[1] == '='){
                int x = eqn[0]-'a';
                int y = eqn[3]-'a';
                graph[x].push_back(y);
                graph[y].push_back(x);
            }
        }
        
        function<void(int,int)> dfs = [&](int node, int c){
            if(color[node] == -1){
                color[node] = c;
                for(int nei: graph[node]){
                    dfs(nei,c);
                }
            }
        };
        
        for(int i = 0; i < sz; i++){
            dfs(i,i);
        }
        
        for(string& eqn: equations){
            if(eqn[1] == '!'){
                int x = eqn[0]-'a';
                int y = eqn[3]-'a';
                if(color[x] == color[y]) return false;
            }
        }
        return true;
    }
};