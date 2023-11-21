class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int n = points.size();
        vector<bool> seen(n,false);
        int used = 0;
        int minCost = 0;
        pq.push({0,0});
        while(used < n){
            auto top = pq.top();
            pq.pop();
            int weight = top.first;
            int currNode = top.second;
            if(!seen[currNode]){
                seen[currNode] = true;
                minCost += weight;
                used++;
                for(int next = 0; next < n; next++){
                    if(!seen[next]){
                        int nextWeight = abs(points[currNode][0] - points[next][0]) + abs(points[currNode][1] - points[next][1]);
                        pq.push({nextWeight,next});
                    }
                }
                
            }
        }
        return minCost;
    }
};