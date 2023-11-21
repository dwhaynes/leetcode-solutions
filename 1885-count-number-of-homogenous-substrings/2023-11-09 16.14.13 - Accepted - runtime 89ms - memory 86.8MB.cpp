class Solution {
public:
    int countHomogenous(string s) {
       vector<long> subs(100001,0);
       long MOD = 1'000'000'007;
       size_t idx = 1;
       long cnt = 1;
       char curr = s[0];
       while(idx < s.size()){
           if(s[idx] == curr){
               cnt++;
               idx++;
           }else{
               subs[cnt]++;
               curr = s[idx];
               cnt = 1;
               idx++;
           }
       }
       subs[cnt]++;

       long ans = 0;
       for(long k = 0; k < subs.size(); k++){
           ans = (ans + (k * (k+1) * subs[k] / 2) % MOD) % MOD;
       }

       return (int) ans;

    }
};