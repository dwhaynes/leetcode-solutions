class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        int mod = code.size();
        if (k==0) return vector<int>(mod,0);
        bool neg = (k < 0);
        if (neg) k = abs(k);
        for(int i = 0; i < mod; i++){
            int sum = 0;
            for(int j = 1; j <= k; j++){
                if(neg) sum += code[(i-j+mod)%mod];
                else sum += code[(i+j)%mod];
            }
            ans.push_back(sum);

        }
        return ans;
    }
};