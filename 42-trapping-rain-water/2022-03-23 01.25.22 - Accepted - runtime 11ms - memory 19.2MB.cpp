class Solution {
public:
    int trap(vector<int>& height) {
        int left = INT_MIN;
        int right = INT_MIN;
        vector<int> left_mask;
        vector<int> ans;
        for(int i = 0; i < height.size(); i++){
            left = max(left, height[i]);
            left_mask.push_back(left);
        }
        for(int i = height.size()-1; i >= 0; i--){
            right = max(right, height[i]);
            ans.push_back(min(left_mask[i], right)-height[i]);
        }
        return accumulate(ans.begin(),ans.end(),0);
    }
};