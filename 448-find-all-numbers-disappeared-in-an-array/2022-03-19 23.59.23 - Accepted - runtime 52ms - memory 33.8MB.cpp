class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int newindex = abs(nums[i])-1;
            if(nums[newindex] > 0) nums[newindex]*=-1;
        }
        vector<int> result;
        for(int i = 1; i <= nums.size(); i++){
            if(nums[i-1] > 0) result.push_back(i);
        }
        return result;
    }
};