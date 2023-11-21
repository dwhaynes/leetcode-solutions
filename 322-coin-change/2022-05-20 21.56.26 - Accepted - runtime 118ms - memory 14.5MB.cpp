class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1,amount+1);
        memo[0] = 0;
        for(int i = 0; i <= amount; i++){
            for(auto coin: coins){
               if(coin <= i) memo[i] = min(memo[i], memo[i-coin]+1); 
            }
        }
        return memo[amount] > amount ? -1 : memo[amount];
    }
};