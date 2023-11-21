class Solution {
    map<int,int> memo;
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (memo.find(n) != memo.end()) return memo[n];
        return memo[n] = fib(n-1) + fib(n-2);
        
    }
};