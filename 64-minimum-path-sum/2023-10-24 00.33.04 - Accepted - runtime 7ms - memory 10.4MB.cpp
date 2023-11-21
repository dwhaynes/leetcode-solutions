class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<vector<int>> dp(M,vector<int>(N,0));
        for(int i = M-1; i >= 0; i--){
            for(int j = N-1; j >= 0; j--){
                if(i == M-1 && j != N-1) dp[i][j] = grid[i][j] + dp[i][j+1];
                else if(i != M-1 && j == N-1) dp[i][j] = grid[i][j] + dp[i+1][j];
                else if(i != M-1 && j != N-1) dp[i][j] = grid[i][j] + min(dp[i][j+1],dp[i+1][j]);
                else dp[i][j] = grid[i][j];
            }
        }
        return dp[0][0];
    }
};