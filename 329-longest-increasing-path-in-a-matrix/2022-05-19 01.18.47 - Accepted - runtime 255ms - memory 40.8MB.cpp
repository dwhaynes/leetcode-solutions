class Solution {
    int m,n;
    vector<vector<int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return 0;
        m = matrix.size();
        n = matrix[0].size();
        auto cache = vector<vector<int>>(m,vector<int>(n,0));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans,dfs(matrix,i,j,cache));
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& cache){
        if(cache[i][j] != 0) return cache[i][j];
        for(auto d: dirs){
            int x = i+d[0], y = j+d[1];
            if(0 <= x && 0 <= y && x < m && y < n && matrix[x][y] > matrix[i][j])
                cache[i][j] = max(cache[i][j],dfs(matrix,x,y,cache));
        }
        return ++cache[i][j];
    }
};