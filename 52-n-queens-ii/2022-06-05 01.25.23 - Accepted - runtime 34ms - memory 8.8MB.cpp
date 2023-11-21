class Solution {
    int size, solutions = 0;
    set<int> diag, antidiag, cols;
    void backtrack(int row){
        if(row == size){
            solutions++;
            return;
        }
        
        for(int col = 0; col < size; col++){
            int currDiag = row - col;
            int currAnti = row + col;
            if(diag.count(currDiag) ||
              antidiag.count(currAnti) ||
              cols.count(col)) continue;
            
            cols.insert(col);
            diag.insert(currDiag);
            antidiag.insert(currAnti);
            
            backtrack(row+1);
            
            cols.erase(col);
            diag.erase(currDiag);
            antidiag.erase(currAnti);
        }
    }
public:
    int totalNQueens(int n) {
        size = n;
        backtrack(0);
        return solutions;
    }
};