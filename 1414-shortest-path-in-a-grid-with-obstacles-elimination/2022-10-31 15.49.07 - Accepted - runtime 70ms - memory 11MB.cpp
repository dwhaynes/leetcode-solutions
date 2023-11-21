class Solution {
    struct Node {
        int r,c,len,k;
        Node(int r, int c, int len, int k):r(r),c(c),len(len),k(k){}
    };
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int R = grid.size(), C = grid[0].size();
        vector<int> dr = {1,0,0,-1}, dc = {0,1,-1,0};
        vector<vector<int>> remaining(R,vector<int>(C,INT_MIN));
        remaining[0][0] = k;
        priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>> pq;
        pq.push({R+C-2,new Node(0,0,0,k)});
        while(!pq.empty()){
            Node* node = pq.top().second;
            pq.pop();
            if(node->r == R-1 && node->c == C-1) return node->len;
            for(int i = 0; i < 4; i++){
                int newR = node->r + dr[i];
                int newC = node->c + dc[i];
                if(newR < 0 || newR >= R || newC < 0 || newC >= C) continue;
                int rem = node->k - grid[newR][newC];
                if(rem >= 0 && rem > remaining[newR][newC]){
                    remaining[newR][newC] = rem;
                    Node* next = new Node(newR,newC,node->len+1,rem);
                    pq.push({R+C-next->r-next->c-1+node->len,next});
                }
             }
        }
        return -1;
    }
};