class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int MOD = 1'000'000'007;
        int N = arr.size();
        sort(arr.begin(),arr.end());
        vector<long> dp(N,1);

        map<int,int> index;
        for(int i = 0; i < N; ++i) index[arr[i]] = i;

        for(int i = 0; i < N; ++i){
            for(int j = 0; j < i; ++j){
                if(arr[i] % arr[j] == 0){
                    int right  = arr[i]/arr[j];
                    if(index.find(right) != index.end()){
                        dp[i] = (dp[i] + dp[j]*dp[index[right]]) % MOD;
                    }
                }
            }
        }
        long ans = 0;
        for(auto x: dp) ans += x;
        return (int) (ans % MOD);
    }
};