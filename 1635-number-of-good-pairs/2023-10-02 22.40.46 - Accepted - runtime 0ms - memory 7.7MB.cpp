class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,vector<int>> pairs;
        for(int i = 0; i < nums.size(); i++){
            pairs[nums[i]].push_back(i);
        }
        int ans = 0;
        for(auto [k,v]: pairs){
            int n = v.size();
            ans += (n * (n-1))/2;
        }
        return ans;
    }
};