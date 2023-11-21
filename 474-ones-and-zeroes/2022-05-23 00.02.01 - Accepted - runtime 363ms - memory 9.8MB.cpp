class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        auto dp = vector<vector<int>>(m+1,vector<int>(n+1,0));
        for(auto s: strs){
            auto count = countzeroesones(s);
            for(int zeroes = m; zeroes >= count[0]; zeroes--){
                for(int ones = n; ones >= count[1]; ones--)
                    dp[zeroes][ones] = max(1 + dp[zeroes-count[0]][ones-count[1]],dp[zeroes][ones]);
            }
        }
        return dp[m][n];
    }
    vector<int> countzeroesones(string& s){
        vector<int> c(2,0);
        for(auto ch:s) c[ch-'0']++;
        return c;
    }
};