class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        while(row < m && matrix[row][n-1] < target) row++;
        if(row >= m) return false;
        int l = 0, r = n-1;
        while(l <= r){
            int m = l + (r-l)/2;
            if(matrix[row][m] == target) return true;
            else if(matrix[row][m] < target){
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        return false;
    }
};