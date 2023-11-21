class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int visited = 101;
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<vector<int>> direction = {{0,1},{1,0},{0,-1},{-1,0}};
        int currDir = 0;
        int chDir = 0;
        
        int row = 0;
        int col = 0;
        vector<int> result;
        result.push_back(matrix[0][0]);
        matrix[0][0] = visited;
        while(chDir < 2){
            while( row + direction[currDir][0] >= 0 &&
            row + direction[currDir][0] < rows &&
            col + direction[currDir][1] >= 0 &&
            col + direction[currDir][1] < cols &&
            matrix[row + direction[currDir][0]][col + direction[currDir][1]] != visited){
                chDir = 0;
                row = row + direction[currDir][0];
                col = col + direction[currDir][1];
                result.push_back(matrix[row][col]);
                matrix[row][col] = visited;
            }
            currDir = (currDir + 1)%4;
            chDir++;
        }
        return result;
    }
};