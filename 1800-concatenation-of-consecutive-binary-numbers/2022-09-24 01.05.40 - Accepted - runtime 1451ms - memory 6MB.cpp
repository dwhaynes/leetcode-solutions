class Solution {
    const int mod = pow(10,9)+7;
public:
    int concatenatedBinary(int n) {
        long res = 0;
        for(int i = 1; i <= n; i++){
            int len = (int)log2(i)+1;
            int bin[len];
            int temp = i;
            for(int j = len-1; j >= 0; j--){
                bin[j] = (temp & 1);
                temp >>= 1;
            }
            for(int j = 0; j < len; j++){
                res = ((res << 1) ^ bin[j]) % mod;
            }
        }
        return res;
    }
};