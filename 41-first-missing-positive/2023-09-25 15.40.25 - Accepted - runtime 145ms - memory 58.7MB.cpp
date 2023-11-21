class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> set;

        for(auto num: nums) set.insert(num);

        int i = 1;
        while(i <= set.size()){
            if(set.find(i) != set.end()) i++;
            else return i;
        }
        return i;
    }
};