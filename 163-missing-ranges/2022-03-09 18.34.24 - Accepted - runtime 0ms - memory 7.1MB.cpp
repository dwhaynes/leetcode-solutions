class Solution {
    vector<int> nums;
    string printGap(int lower, int upper){
        if(lower == upper) return to_string(lower);
        return to_string(lower)+"->"+to_string(upper);
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int prev = lower-1;
        this->nums = nums;
        vector<string> res;
        for(int i = 0; i <= nums.size();i++){
            int curr = (i < nums.size()) ? nums[i] : upper+1;
            if(prev + 1 <= curr - 1) res.push_back(printGap(prev+1,curr-1));
            prev = curr;
        }
        return res;
    }
};