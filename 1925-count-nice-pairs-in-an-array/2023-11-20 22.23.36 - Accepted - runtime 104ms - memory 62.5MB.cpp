class Solution {
    int reverse(int num){
        int ans = 0;
        while(num){
            int digit = num %10;
            ans *= 10;
            ans += digit;
            num /= 10;
        }
        return ans;
    }
public:
    int countNicePairs(vector<int>& nums) {
        int MOD = 1'000'000'007;
        unordered_map<int,int> table;
        vector<int> arr;
        for(auto num: nums){
            arr.push_back(num-reverse(num));
        }
        int count = 0;
        for(auto num: arr){
            count = (count + table[num]) % MOD;
            table[num]++;
        }
        return count;
    }
};