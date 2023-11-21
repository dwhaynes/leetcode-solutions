class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int total = 0;
        int i = 0, j = 0;
        
        while(i < neededTime.size() && j < neededTime.size()){
            int currTotal = 0, currMax = 0;
            
            while(j < neededTime.size() && colors[i] == colors[j]){
                currTotal += neededTime[j];
                currMax = max(currMax,neededTime[j]);
                j++;
            }
            total += currTotal-currMax;
            i = j;
        }
        return total;
    }
};