class Solution {
    map<int,int> cache;
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(cache.find(n) != cache.end()) return cache[n];
        return cache[n] = fib(n-1)+fib(n-2);
    }
};