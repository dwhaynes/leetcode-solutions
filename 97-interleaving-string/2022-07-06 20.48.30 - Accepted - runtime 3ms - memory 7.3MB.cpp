class Solution {
    vector<vector<int>> memo;
    bool helper(string& s1, int i, string& s2, int j, string& s3, int k){
        if(i == s1.size()) return s2.substr(j) == s3.substr(k);
        if(j == s2.size()) return s1.substr(i) == s3.substr(k);
        if(memo[i][j] >= 0) return memo[i][j] == 1 ? true : false;
        bool ans = false;
        if(s3[k] == s1[i] && helper(s1,i+1,s2,j,s3,k+1) ||
           s3[k] == s2[j] && helper(s1,i,s2,j+1,s3,k+1)) ans = true;
        memo[i][j] = ans ? 1 : 0;
        return ans;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        memo = vector<vector<int>>(s1.size(),vector<int>(s2.size(),-1));
        return helper(s1,0,s2,0,s3,0);
    }
};