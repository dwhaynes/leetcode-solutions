class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = 1000000007;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<long> dp(n,1);
        
        map<int,int> index;
        for(int i = 0; i < n; i++) index[arr[i]] = i;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[i] % arr[j] == 0){
                    int right = arr[i] / arr[j];
                    if(index.count(right)) dp[i] = (dp[i] + dp[j] * dp[index[right]]) % mod;
                }
            }
        }
        long ans = 0;
        for(long x: dp) ans+=x;
        return (int) (ans % mod);
    }
};