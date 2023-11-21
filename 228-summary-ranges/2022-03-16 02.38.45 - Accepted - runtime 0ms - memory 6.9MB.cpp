class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        for(int i = 0, j = 0; j < nums.size(); j++){
            i = j;
            while (j+1 < nums.size() && nums[j+1] == nums[j]+1) j++;
            if(i==j) ans.push_back(to_string(nums[i]));
            else ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
        }
        return ans;
    }
};