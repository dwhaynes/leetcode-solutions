class Solution {
public:
    int minDistance(string word1, string word2) {
        int M = word1.size();
        int N = word2.size();

        if(M == 0) return N;
        if(N == 0) return M;

        vector<vector<int>> dp(M+1,vector<int>(N+1,0));
        for(int i = 1; i <= M; i++) dp[i][0] = i;
        for(int i = 1; i <= N; i++) dp[0][i] = i;

        for(int m = 1; m <= M; m++){
            for(int n = 1; n <= N; n++){
                if(word1[m-1] == word2[n-1]) dp[m][n] = dp[m-1][n-1];
                else dp[m][n] = min(dp[m-1][n],min(dp[m][n-1],dp[m-1][n-1]))+1;
            }
        }
        return dp[M][N];
    }
};