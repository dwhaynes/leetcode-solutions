class Solution {
    vector<pair<int,int>> adj[101];
    void dijkstra(vector<int>& received, int source){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,source});
        received[source] = 0;
        
        while(!pq.empty()){
            auto currTime = pq.top().first;
            auto currNode = pq.top().second;
            pq.pop();
            
            if(currTime > received[currNode]) continue;
            
            for(auto edge: adj[currNode]){
                auto time = edge.first;
                auto next = edge.second;
                
                if(currTime + time < received[next]){
                    received[next] = currTime + time;
                    pq.push({received[next],next});
                }
            }
        }
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> received(n+1,INT_MAX);
        for(auto edge: times){
            auto src = edge[0];
            auto dst = edge[1];
            auto wgt = edge[2];
            adj[src].push_back({wgt,dst});
        }
        dijkstra(received,k);
        received[0] = INT_MIN;
        auto ans = *max_element(received.begin(),received.end());
        return ans == INT_MAX ? -1 : ans;
    }
};