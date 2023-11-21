class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        int mod = code.size();
        for(int i = 0; i < mod; i++){
            if(k == 0) ans.push_back(0);
            else{
                int sum = 0;
                if(k > 0){
                    for(int j = 1; j <= k; j++){
                        sum += code[(i+j)%mod];
                    }
                    ans.push_back(sum);
                }
                else {
                    for(int j = k; j < 0; j++){
                        sum += code[(i+j+mod)%mod];
                    }
                    ans.push_back(sum);
                }
            }
        }
        return ans;
    }
};