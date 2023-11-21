class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 1) return false;
        int p = (int)(log(n)/log(4));
        return pow(4,p) == n;
    }
};