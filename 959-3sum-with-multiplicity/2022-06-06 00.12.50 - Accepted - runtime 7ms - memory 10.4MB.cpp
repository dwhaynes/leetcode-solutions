class Solution {
    int count = 0;
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int MOD = 1'000'000'007;
        
        long count[101];
        memset(count,0,sizeof(count));
        int uniq = 0;
        for(int x: arr){
            count[x]++;
            if(count[x] == 1) uniq++;
        }
        
        int keys[uniq];
        memset(keys,0,sizeof(keys));
        
        int t = 0;
        for(int i = 0; i <= 100; i++){
            if(count[i] > 0) keys[t++]=i;
        }
        
        long ans = 0;
        
        for(int i = 0; i < uniq; i++){
            int x = keys[i];
            int T = target - x;
            int j = i, k = uniq-1;
            while(j <= k){
                int y = keys[j], z=keys[k];
                if(y+z < T) j++;
                else if(y+z > T) k--;
                else{
                    if(i < j && j < k) ans+=count[x]*count[y]*count[z];
                    else if(i == j && j < k) ans+= count[x]*(count[x]-1)/2*count[z];
                    else if(i < j && j == k) ans+=count[x]*count[y]*(count[y]-1)/2;
                    else ans+=count[x]*(count[x]-1)*(count[x]-2)/6;
                    ans%= MOD;
                    j++;
                    k--;
                }
            }
        }
        return (int) ans;
    }
};