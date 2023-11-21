class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        using node = pair<int,int>;
        priority_queue<node,vector<node>, greater<node>> pq;
        pq.push({0,0});
        int minCost = 0;
        int used = 0;
        int n = points.size();
        //vector<bool> seen(n);
        bool seen[n];
        memset(seen,false,sizeof(seen));
        while(used < n){
            auto topNode = pq.top();
            pq.pop();
            
            int weight = topNode.first;
            int curr = topNode.second;
            
            if(!seen[curr]){
                minCost += weight;
                seen[curr] = true;
                used++;
                
                for(int next = 0; next < points.size(); next++){
                    if(!seen[next]){
                        int nextWeight = abs(points[next][0] - points[curr][0]) + abs(points[next][1] - points[curr][1]);
                        pq.push({nextWeight,next});
                    }
                }
            }
        }
        return minCost;
    }
};