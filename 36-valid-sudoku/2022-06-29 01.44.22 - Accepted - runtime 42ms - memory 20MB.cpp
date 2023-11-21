class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int N= 9;
        set<char> rows[N];
        set<char> cols[N];
        set<char> boxes[N];
        
        for(int r=0; r < N; r++){
            for(int c=0; c < N; c++){
                char val = board[r][c];
                if(val == '.') continue;
                
                if(rows[r].count(val)) return false;
                rows[r].insert(val);
                if(cols[c].count(val)) return false;
                cols[c].insert(val);
                
                int idx = (r/3)*3 + (c/3);
                if(boxes[idx].count(val)) return false;
                boxes[idx].insert(val);
            }
        }
        return true;
    }
};