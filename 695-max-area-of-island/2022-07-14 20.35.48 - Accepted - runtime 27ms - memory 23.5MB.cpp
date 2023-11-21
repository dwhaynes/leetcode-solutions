class Solution {
    int maxSize = 0;
    int R, C;
    bool isValid(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& seen){
        if(r < 0 || r >= R || c < 0 || c >= C || !grid[r][c] || seen[r][c]) return false;
        return true;
    }
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& seen){
        int size = 0;
        if(isValid(r,c,grid,seen)){
            size++;
            seen[r][c] = true;
        }
        else{
            if(r >= 0 && r < R && c >= 0 && c < C) seen[r][c] = true;
            return 0;
        }
        
        size += dfs(r+1,c,grid,seen);
        size += dfs(r-1,c,grid,seen);
        size += dfs(r,c+1,grid,seen);
        size += dfs(r,c-1,grid,seen);
        return size;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        R = grid.size();
        C = grid[0].size();
        vector<vector<bool>> seen(R,vector<bool>(C,false));
        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                if(grid[r][c]){
                    int size = dfs(r,c,grid,seen);
                    maxSize = max(maxSize,size);
                }else{
                    seen[r][c] = true;
                }
            }
        }
        return maxSize;
    }
};