class Solution {
    using dtype = pair<int,vector<int>>;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<dtype,vector<dtype>,greater<dtype>> pq;
        vector<vector<int>> ans;
        
        for(auto coord: points){
            pq.push({coord[0]*coord[0]+coord[1]*coord[1],coord});
        }
        while(k > 0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};