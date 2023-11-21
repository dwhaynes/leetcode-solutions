class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int mask_sz = 0;
        uint m = n;
        while(m){
            m >>= 1;
            mask_sz++;
        }
        int mask = 0;
        while(mask_sz){
            mask <<= 1;
            mask |= 1;
            mask_sz--;
        }
        return n^mask;
    }
};