class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res, maxHeights(heights.size(),0);
        maxHeights[heights.size()-1] = heights.back();
        for(int i = heights.size()-2; i >= 0; i--){
            maxHeights[i] = max(heights[i],maxHeights[i+1]);
        }
        for(int i = 0; i < heights.size() - 1; i++){
            if(heights[i] > maxHeights[i+1]) res.push_back(i);
        }
        res.push_back(heights.size()-1);
        return res;
    }
};