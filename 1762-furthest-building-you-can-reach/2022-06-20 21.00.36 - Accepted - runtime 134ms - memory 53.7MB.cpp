class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i = 0;i <heights.size()-1; i++){
            int current = heights[i];
            int next = heights[i+1];
            int difference = next - current;
            if(difference < 0) continue;
            if(ladders > 0){
                pq.push(difference);
                ladders--;
            }
            else{
                int smallest = pq.empty() ? 0 : pq.top();
                if(smallest == 0 || difference < smallest) bricks-=difference;
                else{
                    if(!pq.empty()) pq.pop();
                    pq.push(difference);
                    bricks-=smallest;
                }
                if(bricks < 0) return i;
            }
        }
        return heights.size()-1;
    }
};