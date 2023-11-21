class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> buy;
        int minval = INT_MAX;
        int n = prices.size();
        for(int i = 0;i < n; i++){
            minval = min(minval,prices[i]);
            buy.push_back(minval);
        }
        int best = 0;
        for(int i = n-1; i >= 0; i--){
            best = max(best, prices[i]-buy[i]);
        }
        return best;
    }
};