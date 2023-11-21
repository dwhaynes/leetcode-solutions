class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minval = INT_MAX;
        int maxval = INT_MIN;
        int n = prices.size();
        for(int i = 0;i < n; i++){
            minval = min(minval,prices[i]);
            maxval = max(maxval, prices[i]-minval);
        }
        return maxval;
    }
};