class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int nrow = mat.size();
        int ncol = mat[0].size();
        if(nrow * ncol != r * c) return mat;
        vector<vector<int>> ans(r, vector<int>(c,0));
        int wrow = 0, wcol = 0;
        for(int i = 0; i < nrow; i++){
            for(int j = 0; j < ncol; j++){
                ans[wrow][wcol] = mat[i][j];
                wcol++;
                if(wcol == c){
                    wcol = 0;
                    wrow++;
                }
            }
        }
        return ans;
    }
};