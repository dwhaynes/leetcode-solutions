class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size() <= k) return nums;
        unordered_map<int,int> counts;

        for(auto num: nums){
            counts[num]++;
        }

        auto cmp = [&counts](int i, int j){return counts[i] > counts[j];};
        priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);

        for(auto [key,val]: counts){
            pq.push(key);
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans;
        for(int i = 0;i < k; i++){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};