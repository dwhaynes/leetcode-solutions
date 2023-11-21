class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        vector<vector<int>> ans = {{1},{1,1}};
        for(int i = 2; i < numRows; i++){
            vector<int> temp = {1};
            for(int j = 1; j < ans.back().size(); j++){
                temp.push_back(ans.back()[j-1] + ans.back()[j]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};