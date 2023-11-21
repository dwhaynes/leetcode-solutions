class Solution {
    vector<vector<int>> grid;
    vector<vector<int>> cache;
    int M,N;
    bool isValid(int r, int c){
        return (r >= 0 && c >= 0 && r < M && c < N && grid[r][c] == 0);
    }
    void dfs(int r, int c){
        if(cache[r][c] != 0) return;
        if(r == M-1 && c == N-1){
            cache[r][c]=1;
            return;
        }
        if(isValid(r+1,c)) dfs(r+1,c);
        if(isValid(r,c+1)) dfs(r,c+1);
        if(isValid(r+1,c)) cache[r][c] += cache[r+1][c];
        if(isValid(r,c+1)) cache[r][c] += cache[r][c+1];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        this->grid = obstacleGrid;
        M = grid.size();
        N = grid[0].size();
        cache = vector<vector<int>>(M,vector<int>(N,0));
        dfs(0,0);
        return cache[0][0];
    }
};