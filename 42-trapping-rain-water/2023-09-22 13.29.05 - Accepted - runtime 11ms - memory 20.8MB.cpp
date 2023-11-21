class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int maxval;

        vector<int> left(n,0), right(n,0);

        maxval = height[0];
        for(int i = 0; i < n; i++){
            maxval = max(maxval, height[i]);
            left[i] = maxval;
        }

        maxval = height[n-1];
        for(int i = n-1; i >= 0; i--){
            maxval = max(maxval, height[i]);
            right[i] = maxval;
            ans += (min(left[i],right[i]) - height[i]);
        }

        return ans;
        
    }
};