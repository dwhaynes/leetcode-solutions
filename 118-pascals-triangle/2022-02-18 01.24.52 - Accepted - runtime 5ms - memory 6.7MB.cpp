class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return {{1}};
        result.push_back({1});
        if (numRows == 2) return {{1},{1,1}};
        result.push_back({1,1});
        for(int r = 2; r < numRows; r++){
            vector<int> row = {1};
            for(int c = 1; c < r; c++){
                row.push_back(result[r-1][c-1] + result[r-1][c]);
            }
            row.push_back(1);
            result.push_back(row);
        }
        return result;
        
    }
};