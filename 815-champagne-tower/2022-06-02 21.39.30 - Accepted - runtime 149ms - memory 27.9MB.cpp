class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tower;
        for(int i = 0; i <= 101; i++){
            tower.push_back(vector<double>(i+1,0.0));
        }
        tower[0][0] = double(poured);
        for(int i = 1; i < 101; i++){
            for(int j = 1; j < tower[i].size(); j++){
                auto available = tower[i-1][j-1];
                tower[i-1][j-1] = min(tower[i-1][j-1],1.0);
                available -= tower[i-1][j-1];
                tower[i][j-1]+=available/2;
                tower[i][j]+=available/2;
            }
            tower[i][i] = tower[i][0];
        }
        return tower[query_row][query_glass];
    }
};