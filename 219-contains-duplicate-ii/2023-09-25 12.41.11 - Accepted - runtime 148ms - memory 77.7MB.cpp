class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> store;
        for(int i = 0; i < nums.size();i++){
            if(store.find(nums[i]) != store.end()){
                if(i - store[nums[i]] <= k) return true;
            }
            store[nums[i]] = i;
        }
        return false;
    }
};