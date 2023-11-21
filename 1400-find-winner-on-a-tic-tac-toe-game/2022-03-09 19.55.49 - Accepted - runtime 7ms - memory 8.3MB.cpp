class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int diag1 = 0;
        int diag2 = 0;
        int r[3] = {0,0,0};
        int c[3] = {0,0,0};
        int p = 1;
        for(auto move: moves){
            if(move[0] == move[1]) diag1+=p;
            if(move[0] == 2-move[1]) diag2+=p;
            r[move[0]]+=p;
            c[move[1]]+=p;
            p*=-1;
            if(diag1 == 3 || diag2 == 3) return "A";
            if(diag1 == -3 || diag2 == -3) return "B";
            for(int i = 0; i < 3; i++){
                if(r[i] == 3 || c[i] == 3) return "A";
                if(r[i] == -3 || c[i] == -3) return "B";
            }
        }
        return moves.size() < 9 ? "Pending" : "Draw";
    }
};