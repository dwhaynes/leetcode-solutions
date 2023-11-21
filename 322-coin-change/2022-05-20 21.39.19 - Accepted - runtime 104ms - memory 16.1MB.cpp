class Solution {
    int coinChange(vector<int>& coins, int amount, vector<int>& count){
        if(amount < 0) return -1;
        if(amount == 0) return 0;
        if(count[amount-1] != 0) return count[amount-1];
        int min = INT_MAX;
        for(auto coin: coins){
            int res = coinChange(coins,amount-coin,count);
            if(res >= 0 && res < min) min = res+1;
        }
        count[amount-1] = (min == INT_MAX)? -1 : min;
        return count[amount-1];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount < 1) return 0;
        vector<int> count(amount,0);
        return coinChange(coins,amount,count);
    }
};