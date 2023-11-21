class Solution {
    vector<vector<vector<int>>> memo;
    int MOD = 1e9+7;
    int n;
    int m;
    int dp(int i, int maxSoFar, int remain){
        if(i == n){
            return (remain == 0) ? 1 : 0;
        }
        if(remain < 0) return 0;
        if(memo[i][maxSoFar][remain] != -1) return memo[i][maxSoFar][remain];
        
        int ans = 0;
        for(int num = 1; num <= maxSoFar; num++)
            ans = (ans + dp(i+1, maxSoFar,remain)) % MOD;

        for(int num = maxSoFar+1; num <= m; num++)
            ans = (ans + dp(i+1, num,remain-1)) % MOD;

        memo[i][maxSoFar][remain] = ans;
        return ans;
    }
public:
    int numOfArrays(int n, int m, int k) {
        memo = vector(n,vector(m+1,vector(k+1,-1)));
        this->n = n;
        this->m = m;
        return dp(0,0,k);
    }
};