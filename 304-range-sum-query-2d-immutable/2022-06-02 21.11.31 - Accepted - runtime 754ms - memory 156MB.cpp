class NumMatrix {
    vector<vector<int>> cumsum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++){
            vector<int> temp = {matrix[i][0]};
            for(int j = 1; j < matrix[0].size();j++){
                temp.push_back(temp[j-1]+matrix[i][j]);
            }
            cumsum.push_back(temp);
        }
        for(int i = 1; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                cumsum[i][j]+=cumsum[i-1][j];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int region = cumsum[row2][col2];
        if(row1 > 0) region-= cumsum[row1-1][col2];
        if(col1 > 0) region-= cumsum[row2][col1-1];
        if(row1 > 0 && col1 > 0) region+= cumsum[row1-1][col1-1];
        return region;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */