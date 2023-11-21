class Solution {
    void transpose(vector<vector<int>>& matrix){
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    void flip(vector<vector<int>>& matrix){
        for(int i = 0; i < matrix.size(); i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        flip(matrix);
    }
};