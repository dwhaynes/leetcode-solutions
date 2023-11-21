class Solution {
    int count = 0;
    vector<vector<bool>> seen;
    int m, n;
    vector<vector<char>> grid;
    void dfs(int r, int c){
        if(r < 0 || r >= m || c < 0 || c >= n || seen[r][c]) return;
        if(grid[r][c] == '1' && !seen[r][c]){
            seen[r][c]=true;
            dfs(r-1,c);
            dfs(r+1,c);
            dfs(r,c-1);
            dfs(r,c+1);
        }
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        seen = vector<vector<bool>>(m,vector<bool>(n,false));
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(grid[r][c] == '1' && !seen[r][c]){
                    count++;
                    dfs(r,c);
                }
            }
        }
        return count;
    }
};