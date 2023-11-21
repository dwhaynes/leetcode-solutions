class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       vector<map<char,bool>> rows(9), cols(9), box(9);
       for(int i = 0; i < 9; i++){
           for(int j = 0; j < 9; j++){
               if(board[i][j] != '.'){
                   int boxid = (i/3)*3 + (j/3);
                   if(rows[i][board[i][j]] || cols[j][board[i][j]] || box[boxid][board[i][j]]) return false;
                   rows[i][board[i][j]] = true;
                   cols[j][board[i][j]] = true;
                   box[boxid][board[i][j]] = true;
               }
           }
       }
       return true; 
    }
};