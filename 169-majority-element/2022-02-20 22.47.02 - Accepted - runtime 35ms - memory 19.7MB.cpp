class Solution {
    map<int,int> count;
public:
    int majorityElement(vector<int>& nums) {
        for(auto n: nums) count[n]++;
        return max_element(count.begin(),count.end(),[](const pair<int,int>& a, const pair<int,int>& b){
            return a.second < b.second;
        })->first;
    }
};