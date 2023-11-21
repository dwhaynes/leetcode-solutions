class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprof = -1;
        int minval = 10000;
        for(int i = 0; i < prices.size(); i++){
            minval = min(minval,prices[i]);
            maxprof = max(maxprof,prices[i]-minval);
        }
        return maxprof;
    }
};