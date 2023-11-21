class Solution {
    vector<vector<int>> memo;

    int recurse(string& w1, string& w2, int m, int n){
        if(m == 0) return n;
        if(n == 0) return m;

        if(memo[m][n] != -1) return memo[m][n];

        int ans;

        if(w1[m-1] == w2[n-1]) ans = recurse(w1,w2,m-1,n-1);
        else{
            int r = recurse(w1,w2,m-1,n-1);
            int i = recurse(w1,w2,m-1,n);
            int d = recurse(w1,w2,m,n-1);
            ans = min(i,min(d,r))+1;
        }
        
        return memo[m][n] = ans;
    }
public:
    int minDistance(string word1, string word2) {
        memo = vector<vector<int>>(word1.size()+1,vector<int>(word2.size()+1,-1));
        return recurse(word1,word2,word1.size(),word2.size());
    }
};