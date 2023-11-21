class Solution {
    vector<vector<int>> memo;
    int lcs(string& w1, string& w2, int m, int n){
        if(m == 0 || n == 0) return 0;
        if(memo[m][n] > 0) return memo[m][n];
        if(w1[m-1] == w2[n-1]) return 1 + lcs(w1,w2,m-1,n-1);
        else memo[m][n] = max(lcs(w1,w2,m-1,n),lcs(w1,w2,m,n-1));
        return memo[m][n];
    }
public:
    int minDistance(string w1, string w2) {
        memo = vector<vector<int>>(w1.size()+1,vector<int>(w2.size()+1, 0));
        return w1.size() + w2.size() - 2*lcs(w1,w2,w1.size(),w2.size());
    }
};