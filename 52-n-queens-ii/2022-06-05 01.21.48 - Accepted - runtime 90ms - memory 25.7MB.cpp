class Solution {
    int size;
    int backtrack(int row, set<int> diag, set<int> antidiag, set<int> cols){
        if(row == size) return 1;
        int solutions = 0;
        for(int col = 0; col < size; col++){
            int currDiag = row-col;
            int currAnti = row + col;
            if(diag.count(currDiag) ||
              antidiag.count(currAnti) ||
              cols.count(col)) continue;
            
            cols.insert(col);
            diag.insert(currDiag);
            antidiag.insert(currAnti);
            
            solutions += backtrack(row+1,diag,antidiag,cols);
            
            cols.erase(col);
            diag.erase(currDiag);
            antidiag.erase(currAnti);
        }
        return solutions;
    }
public:
    int totalNQueens(int n) {
        size = n;
        return backtrack(0,{},{},{});
    }
};