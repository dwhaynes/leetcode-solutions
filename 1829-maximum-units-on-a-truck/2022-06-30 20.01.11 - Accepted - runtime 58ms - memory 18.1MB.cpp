class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int count = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> pq;
        for(auto box:boxTypes) pq.push({box[1],box[0]});
        
        while(!pq.empty() && truckSize != 0){
            auto curr = pq.top(); pq.pop();
            int take = min(curr.second,truckSize);
            count+=take*curr.first;
            truckSize-=take;
            //if(curr.first == take && curr.second > 1) pq.push({curr.first,--curr.second});
        }
        return count;
    }
};