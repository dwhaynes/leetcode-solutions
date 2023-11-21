class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        int dir = 0;
        vector<vector<int>> deltas = {{0,1},{-1,0},{0,-1},{1,0}};
        for(auto ch: instructions){
            if(ch == 'L'){
                dir = (dir+3)%4;
            }
            else if(ch == 'R'){
                dir = (dir+1)%4;
            }else{
                x+=deltas[dir][1];
                y+=deltas[dir][0];
            }
        }
        return (x == 0 && y == 0) || (dir != 0);
    }
};