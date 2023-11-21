class Solution {
    vector<pair<int,int>> non_zero_cells(vector<vector<int>> M){
        vector<pair<int,int>> ret;
        for(int row = 0; row < M.size(); row++){
            for(int col = 0; col < M.size(); col++){
                if(M[row][col]) ret.push_back({row,col});
            }
        }
        return ret;
    }
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        auto A_ones = non_zero_cells(img1);
        auto B_ones = non_zero_cells(img2);
        
        int maxOverlaps = 0;
        map<pair<int,int>,int> groupCount;
        
        for(auto a: A_ones){
            for(auto b: B_ones){
                pair<int,int> vec({b.first-a.first,b.second-a.second});
                groupCount[vec]++;
                maxOverlaps = max(maxOverlaps,groupCount[vec]);
            }
        }
        return maxOverlaps;
    }
};