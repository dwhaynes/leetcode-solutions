class Solution {
    using v2 = vector<vector<int>>;
    using v3 = vector<v2>;
    int M = 1000000007;
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        v3 memo = v3(m,v2(n,vector<int>(maxMove+1,-1)));
        return findPaths(m,n,maxMove,startRow,startColumn,memo);
    }
    
    int findPaths(int m, int n, int N, int i, int j, v3& memo){
        if(i == m || j == n || i < 0 || j < 0) return 1;
        if(N == 0) return 0;
        if(memo[i][j][N] >= 0) return memo[i][j][N];
        memo[i][j][N] = (
            (findPaths(m,n,N-1,i+1,j,memo) + findPaths(m,n,N-1,i-1,j,memo))%M +
            (findPaths(m,n,N-1,i,j+1,memo) + findPaths(m,n,N-1,i,j-1,memo))%M
        )%M;
        
        return memo[i][j][N];
    }
};