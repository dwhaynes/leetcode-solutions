class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int result = 0;
        
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c]){
                    result+=4;
                    if(r > 0 && grid[r-1][c]) result -= 2;
                    if(c > 0 && grid[r][c-1]) result -= 2;
                }
            }
        }
        return result;
    }
};