class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> ans = vector<vector<int>>(m,vector<int>(n,1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans[i][n-j-1]^=image[i][j];
            }
        }
        return ans;
    }
};