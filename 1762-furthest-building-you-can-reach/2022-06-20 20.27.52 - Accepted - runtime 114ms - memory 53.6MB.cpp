class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> allocations;
        for(int i = 0; i < heights.size()-1;i++){
            int current_height = heights[i];
            int next_height = heights[i+1];
            int difference = next_height-current_height;
            if(difference <= 0) continue;
            if(ladders > 0){
                allocations.push(difference);
                ladders--;
            }
            else{
                int smallest = allocations.empty() ? 0 : allocations.top();
                if(smallest == 0 || difference < smallest) bricks-=difference;
                else{
                    if(!allocations.empty()) allocations.pop();
                    allocations.push(difference);
                    bricks-=smallest;
                }
                if(bricks < 0) return i;
            }
        }
        return heights.size()-1;
    }
};