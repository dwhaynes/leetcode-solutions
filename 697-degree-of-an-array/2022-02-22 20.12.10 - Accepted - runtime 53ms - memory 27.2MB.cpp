class Solution {
    map<int, int> left, right, count;

public:
    int findShortestSubArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            if(left.find(x) == left.end()) left[x]=i;
            right[x]=i;
            count[x]++;
        }
        int ans = nums.size();
        int deg = std::max_element(count.begin(), count.end(), [] (const pair<int,int> & p1, const pair<int,int> & p2) {
        return p1.second < p2.second;
  })->second;
        for(auto kv: count){
            if(count[kv.first] == deg){
                ans = min(ans,right[kv.first] - left[kv.first] +1);
            }
        }
        return ans;
    }
};