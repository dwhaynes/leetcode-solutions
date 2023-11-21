class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ctr = 0;
        while(n){
            if(n & 1) ctr++;
            n >>= 1;
        }
        return ctr;
    }
};