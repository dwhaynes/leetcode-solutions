class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> hist;
        int dupe = -1, missing = 1;
        for(auto num: nums) hist[num]++;
        for(int i = 1; i <= nums.size();i++){
            if(hist.count(i)){
                if(hist[i] == 2) dupe = i;
            }else{
                missing = i;
            }
        }
        return {dupe,missing};
    }
};