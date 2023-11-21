class Solution {
public:
    int countHomogenous(string s) {
       long MOD = 1'000'000'007;
       long ans = 0;
       size_t idx = 1;
       long cnt = 1;
       char curr = s[0];
       while(idx < s.size()){
           if(s[idx] == curr){
               cnt++;
               idx++;
           }else{
               ans = (ans + (cnt * (cnt+1) / 2) % MOD) % MOD;
               curr = s[idx];
               cnt = 1;
               idx++;
           }
       }
       ans = (ans + (cnt * (cnt+1) / 2) % MOD) % MOD;

       return (int) ans;

    }
};