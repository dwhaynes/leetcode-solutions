class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        vector<vector<int>> ps(r+1,vector<int>(c+1,0));
        for(int i = 1; i < r+1; i++){
            for(int j = 1; j < c+1; j++){
                ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        
        int count = 0, currSum;
        map<int,int> h;
        
        for(int r1 = 1; r1 < r+1; r1++){
            for(int r2 = r1; r2 < r+1; r2++){
                h.clear();
                h[0]=1;
                for(int col = 1; col < c+1; col++){
                    currSum = ps[r2][col] - ps[r1-1][col];
                    count += h[currSum-target];
                    h[currSum]++;
                }
            }
        }
        return count;
    }
};