class Solution {
    int binarySearch(vector<int> sub, int num){
        int l = 0, r = sub.size()-1, m;
        while (l < r){
            m = l + (r-l)/2;
            if(sub[m] == num) return m;
            if(sub[m] < num) l = m+1;
            else r = m;
        }
        return l;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub = {nums[0]};
        for(int i = 1; i < nums.size(); i++){
            int num = nums[i];
            if (num > sub.back()) sub.push_back(num);
            else{
                int j = binarySearch(sub,num);
                sub[j] = num;
            }
        }
        return sub.size();
    }
};