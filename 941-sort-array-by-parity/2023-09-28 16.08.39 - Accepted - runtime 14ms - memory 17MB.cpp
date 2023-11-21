class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> odd, even;
        for(auto n: nums){
            if(n%2) odd.push_back(n);
            else even.push_back(n);
        }
        even.insert(even.end(),odd.begin(),odd.end());
        return even;
    }
};