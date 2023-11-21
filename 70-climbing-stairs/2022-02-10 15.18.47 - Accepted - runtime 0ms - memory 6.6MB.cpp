class Solution {
    unordered_map<int,int> memo = {{0,1},{1,1}};
public:
    int climbStairs(int n) {
        if(n < 0) return 0;
        if(memo.find(n) != memo.end()) return memo[n];
        
        return memo[n] =  climbStairs(n-1) + climbStairs(n-2);
    }
};