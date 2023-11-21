class Solution {
    map<pair<int,int>,int> paths;
    int M, N;
    int dfs(int m, int n){
        if(m == M-1 && n == N-1) return 1;
        if(paths.find({m,n}) != paths.end()) return paths[{m,n}];
        int sum = 0;
        if(m+1 < M) sum+=dfs(m+1,n);
        if(n+1 < N) sum+=dfs(m,n+1);
        paths[{m,n}]=sum;
        return sum;
    }
public:
    int uniquePaths(int m, int n) {
        M = m;
        N = n;
        return dfs(0,0);
    }
};