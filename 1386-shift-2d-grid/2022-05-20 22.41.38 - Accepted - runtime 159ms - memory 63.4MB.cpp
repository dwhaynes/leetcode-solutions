class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        //vector<vector<int>> ans;
        int M = grid.size();
        int N = grid[0].size();
        for(int it = 0; it < k; it++){
            vector<int> temp;
            temp.push_back(grid[M-1][N-1]);
            for(int i = 0; i < M; i++)
                for(int j = 0; j < N; j++)
                    temp.push_back(grid[i][j]);
            temp.pop_back();
            int t = 0;
            for(int i = 0; i < M; i++)
                for(int j = 0; j < N; j++)
                    grid[i][j] = temp[t++];
        }
        return grid;
    }
};