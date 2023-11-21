class Solution {

public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int mod = pow(10,9)+7;
        vector<pair<int,int>> cand;
        for(int i = 0; i < n; i++) cand.push_back({efficiency[i],speed[i]});
        sort(cand.begin(),cand.end(),[](auto& a, auto& b){
            return a.first > b.first;
        });
        priority_queue<int,vector<int>,greater<int>> pq;
        long speedSum = 0, perf = 0;
        for(auto p: cand){
            int currEff = p.first;
            int currSpeed = p.second;
            if(pq.size() > k-1){
                speedSum -= pq.top();
                pq.pop();
            }
            pq.push(currSpeed);
            speedSum += currSpeed;
            perf = max(perf,speedSum*currEff);
        }
        return (int)(perf % mod);
    }
};