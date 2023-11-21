class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);
        
        for(int i = 1; i < nums.size(); i++){
            int num = nums[i];
            if(num > sub.back()) sub.push_back(num);
            else{
                int j = 0;
                while(num > sub[j]) j++;
                sub[j]=num;
            }
        }
        return sub.size();
    }
};