class Solution {
public:
    int countHomogenous(string s) {
       map<long,long> subs;
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
       for(auto& [k,v]: subs){
           ans = (ans + (k * (k+1) * v / 2) % MOD) % MOD;
       }
       return (int) ans;

    }
};