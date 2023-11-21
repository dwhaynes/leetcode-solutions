class Solution {
    vector<vector<int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int N, M;
    vector<vector<int>> grid;
    vector<vector<int>> getNext(int row, int col){
        vector<vector<int>> next;
        for(int i = 0; i < dir.size(); i++){
            int newRow = row + dir[i][0];
            int newCol = col + dir[i][1];
            if(newRow < 0 || newRow >= M || newCol < 0 || newCol >= N || grid[newRow][newCol] != 0) continue;
            
            next.push_back({newRow,newCol});
        }
        return next;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        if(grid[0][0] != 0 || grid[M-1][N-1] != 0) return -1;
        this->grid = grid;
        queue<vector<int>> q;
        q.push({0,0,1});
        auto visited = vector<vector<bool>>(M,vector<bool>(N,false));
        visited[0][0]=true;
        
        while(!q.empty()){
            auto cell = q.front();
            q.pop();
            int row = cell[0];
            int col = cell[1];
            int distance = cell[2];
            if(row == M-1 && col == N-1) return distance;
            
            for(auto next: getNext(row,col)){
                int newRow = next[0];
                int newCol = next[1];
                if(visited[newRow][newCol]) continue;
                visited[newRow][newCol] = true;
                q.push({newRow,newCol,distance+1});
            }
        }
        return -1;
    }
};