class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = {{1}};
        if(numRows == 1) return ans;
        
        for(int n = 1; n < numRows; n++){
            vector<int> temp = {1};
            for(int k = 0; k < n; k++){
                temp.push_back(temp.back()*(n-k)/(k+1));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};