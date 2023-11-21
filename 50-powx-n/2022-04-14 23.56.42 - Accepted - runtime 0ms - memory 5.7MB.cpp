class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.;
        long pow = n;
        int pos = 31;
        bool neg = n <= 0;
        if (neg) pow*=-1;
        while(!(pow & (1L << pos))) pos--;
        double ans = 1.;
        while(pos >= 0){
            ans*=ans;
            if(pow & (1 << pos)){
                ans*=x;
            }
            pos--;
        }
        return neg ? 1/ans : ans;
    }
};