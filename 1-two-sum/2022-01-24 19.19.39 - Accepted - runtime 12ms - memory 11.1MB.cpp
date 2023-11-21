class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> diffs;
        for(int i = 0; i < nums.size(); i++){
            if(diffs.find(nums[i]) != diffs.end()){
                return {diffs[nums[i]],i};
            }else{
                diffs[target-nums[i]] = i;
            }
        }
        return {};
    }
};