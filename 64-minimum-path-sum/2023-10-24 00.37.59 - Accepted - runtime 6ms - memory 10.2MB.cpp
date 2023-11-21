class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<int> dp(N,0);
        for(int i = M-1; i >= 0; i--){
            for(int j = N-1; j >= 0; j--){
                if(i == M-1 && j != N-1) dp[j] = grid[i][j] + dp[j+1];
                else if(i != M-1 && j == N-1) dp[j] = grid[i][j] + dp[j];
                else if(i != M-1 && j != N-1) dp[j] = grid[i][j] + min(dp[j+1],dp[j]);
                else dp[j] = grid[i][j];
            }
        }
        return dp[0];
    }
};