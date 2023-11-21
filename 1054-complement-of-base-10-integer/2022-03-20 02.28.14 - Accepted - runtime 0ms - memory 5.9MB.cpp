class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int mask_sz = 0;
        int m = n;
        while(m){
            m >>= 1;
            mask_sz++;
        }
        int mask = 1;
        mask <<= mask_sz;
        mask--;
        return n^mask;
    }
};