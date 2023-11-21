class Solution {
    struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        if(a.first == b.first) return a > b;
        return a.first > b.first;
    }
    };
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> ans;
        for(auto num: arr) pq.push({abs(num-x),num});
        while(!pq.empty() && k > 0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};