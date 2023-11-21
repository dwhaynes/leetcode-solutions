class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = {1};
        for(int k=1; k <= rowIndex; k++)
            row.push_back(row[row.size()-1] * (long)(rowIndex - k +1) / k);
        return row;
    }
};