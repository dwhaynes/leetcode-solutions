class Solution {
    void sortDiagonal(size_t row, size_t col, vector<vector<int>>& mat){
        size_t M = mat.size();
        size_t N = mat[0].size();
        
        priority_queue<int,vector<int>, greater<int>> diagonal;
        
        size_t diagonal_len = min(M-row,N-col);
        for(size_t i=0; i < diagonal_len; i++) diagonal.push(mat[row+i][col+i]);
        
        for(size_t i=0; i < diagonal_len;i++){
            mat[row+i][col+i] = diagonal.top();
            diagonal.pop();
        }
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        size_t M = mat.size();
        size_t N = mat[0].size();
        
        for(size_t row=0; row < M; row++) sortDiagonal(row,0,mat);
        
        for(size_t col=0; col < N; col++) sortDiagonal(0,col,mat);
        
        return mat;
    }
};