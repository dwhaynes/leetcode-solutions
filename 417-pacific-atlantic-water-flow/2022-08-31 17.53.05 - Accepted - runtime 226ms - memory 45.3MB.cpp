class Solution {
    vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
    int nrows;
    int ncols;
    vector<vector<int>> landHeights;
public:
    vector<vector<bool>> bfs(queue<vector<int>>& q){
        vector<vector<bool>> reachable(nrows,vector<bool>(ncols));
        while(!q.empty()){
            auto cell = q.front(); q.pop();
            reachable[cell[0]][cell[1]] = true;
            for(auto dir: directions){
                int newrow = cell[0] + dir[0];
                int newcol = cell[1] + dir[1];
                if(newrow < 0 || newrow >= nrows || newcol < 0 || newcol >= ncols)
                    continue;
                if(reachable[newrow][newcol]) continue;
                if(landHeights[newrow][newcol] < landHeights[cell[0]][cell[1]]) continue;
                q.push({newrow,newcol});
            }
        }
        return reachable;
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.size() == 0 || heights[0].size() == 0) return {};
        
        nrows = heights.size();
        ncols = heights[0].size();
        landHeights = heights;
        
        queue<vector<int>> pacific, atlantic;
        for(int i = 0; i < nrows; i++){
            pacific.push({i,0});
            atlantic.push({i,ncols-1});
        }
        for(int i = 0; i < ncols; i++){
            pacific.push({0,i});
            atlantic.push({nrows-1,i});
        }
        auto preachable = bfs(pacific);
        auto areachable = bfs(atlantic);
        
        vector<vector<int>> common;
        for(int i = 0; i < nrows; i++){
            for(int j = 0; j < ncols; j++){
                if(preachable[i][j] && areachable[i][j]) common.push_back({i,j});
            }
        }
        return common;
    }
};