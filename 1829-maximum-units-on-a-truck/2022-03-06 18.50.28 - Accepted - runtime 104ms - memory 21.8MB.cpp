class Solution {
    struct comp{
        bool operator()(vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        }
    };
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<vector<int>, vector<vector<int>>, comp> pq;
        for(auto box: boxTypes) pq.push(box);
        int units = 0;
        while(!pq.empty()){
            auto box = pq.top();
            pq.pop();
            int boxes = min(truckSize, box[0]);
            units+=boxes*box[1];
            truckSize-=boxes;
            if(truckSize == 0) break;
        }
        return units;
    }
};