class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,vector<int>> sets;
        for(int i = 0; i < nums.size(); i++) sets[nums[i]].push_back(i);
        for(auto& [key,v]: sets){
            if(v.size() > 1){
                for (int i = 1; i < v.size(); i++){
                    if(v[i] - v[i-1] <= k) return true;
                }
            }
        }
        return false;
    }
};