class Solution {
    vector<int> count(int N){
        vector<int> ans(10);
        while(N > 0){
            ans[N%10]++;
            N/=10;
        }
        return ans;
    }
public:
    bool reorderedPowerOf2(int n) {
        vector<int> A(count(n));
        for(int i = 0; i < 31; i++)
            if(A == count(1 << i)) return true;
        return false;
    }
};