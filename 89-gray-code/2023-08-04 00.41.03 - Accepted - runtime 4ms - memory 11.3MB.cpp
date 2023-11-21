class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 1) return {0,1};
        vector<int> ans(1 << n, 0);
        ans[1] = 1;
        for(int depth = 1; depth < n; depth++){
            int barrier = 1 << depth;
            int writer = barrier;
            for(int reader = barrier-1; reader >= 0; reader--,writer++){
                ans[writer] = ans[reader] | (1 << depth);
            }
        }
        return ans;
    }
};