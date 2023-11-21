class Solution {
public:
    int countHomogenous(string s) {
       map<pair<char,long>,long> subs;
       long MOD = 1'000'000'007;
       size_t idx = 1;
       long cnt = 1;
       char curr = s[0];
       while(idx < s.size()){
           if(s[idx] == curr){
               cnt++;
               idx++;
           }else{
               subs[{curr,cnt}]++;
               curr = s[idx];
               cnt = 1;
               idx++;
           }
       }
       subs[{curr,cnt}]++;

       long ans = 0;
       for(auto& [k,v]: subs){
           ans = (ans + (k.second * (k.second+1) * v / 2) % MOD) % MOD;
       }
       return (int) ans;

    }
};