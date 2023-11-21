class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int R = grid.size();
        int C = grid[0].size();
        int len = 0;
        vector<vector<int>> remaining(R,vector<int>(C,INT_MIN));
        vector<int> dr = {1,0,0,-1}, dc = {0,1,-1,0};
        queue<vector<int>> q;
        q.push({0,0,k});
        while(!q.empty()){
            for(int i = q.size(); i > 0; i--){
                auto p = q.front();
                q.pop();
                if(p[0] == R-1 && p[1] == C-1) return len;
                for(int j = 0; j < 4; j++){
                    int nextR = p[0]+dr[j];
                    int nextC = p[1]+dc[j];
                    if(nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) continue;
                    int rem = p[2] - grid[nextR][nextC];
                    if(rem >= 0 && rem > remaining[nextR][nextC]){
                        q.push({nextR,nextC,rem});
                        remaining[nextR][nextC] = rem;
                    }
                }
            }
            len++;
        }
        return -1;
    }
};