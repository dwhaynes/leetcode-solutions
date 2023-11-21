class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, r = 0, score = 0;
        int maxscore = INT_MIN;
        int count[10001] = {0};
        while(r < nums.size()){
            score+=nums[r];
            count[nums[r]]++;
            while(count[nums[r]] > 1){
                score-=nums[l];
                count[nums[l]]--;
                l++;
            }
            maxscore = max(maxscore,score);
            r++;
        }
        return maxscore;
    }
};