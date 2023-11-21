class Solution {
    map<int, int> left, right, count;
    template<typename KeyType, typename ValueType> 
std::pair<KeyType,ValueType> get_max( const std::map<KeyType,ValueType>& x ) {
  using pairtype=std::pair<KeyType,ValueType>; 
  return *std::max_element(x.begin(), x.end(), [] (const pairtype & p1, const pairtype & p2) {
        return p1.second < p2.second;
  }); 
}
public:
    int findShortestSubArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            if(left.find(x) == left.end()) left[x]=i;
            right[x]=i;
            count[x]++;
        }
        int ans = nums.size();
        int deg = get_max(count).second;
        for(auto kv: count){
            if(count[kv.first] == deg){
                ans = min(ans,right[kv.first] - left[kv.first] +1);
            }
        }
        return ans;
    }
};