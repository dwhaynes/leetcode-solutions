class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int r = 0; r < matrix.size(); r++){
            for(int c = 0; c < matrix[0].size(); c++){
                pq.push(matrix[r][c]);
            }
        }
        while(!pq.empty() && k > 1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};