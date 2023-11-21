class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;

        int candidate1 = INT_MIN;
        int candidate2 = INT_MIN;

        for(int n : nums){
            if(candidate1 == n) count1++;
            else if (candidate2 == n) count2++;
            else if (count1 == 0){
                candidate1 = n;
                count1++;
            }
            else if (count2 == 0){
                candidate2 = n;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        vector<int> result;

        count1 = 0;
        count2 = 0;

        for(int n: nums){
            if(candidate1 != INT_MIN && n == candidate1) count1++;
            if(candidate2 != INT_MIN && n == candidate2) count2++;
        }
        int n = nums.size();
        if (count1 > n/3) result.push_back(candidate1);
        if (count2 > n/3) result.push_back(candidate2);
        return result;
    }
};