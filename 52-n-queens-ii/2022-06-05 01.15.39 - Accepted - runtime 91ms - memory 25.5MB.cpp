class Solution {
    int size;
    
    int backtrack(int row, set<int> diagonals, set<int> antidiagonals, set<int> cols){
        if(row == size) return 1;
        
        int solutions = 0;
        for(int col = 0; col < size; col++){
            int currDiag = row - col;
            int currAntiDiag = row + col;
            if(cols.count(col) || diagonals.count(currDiag) || antidiagonals.count(currAntiDiag)) continue;
            cols.insert(col);
            diagonals.insert(currDiag);
            antidiagonals.insert(currAntiDiag);
            
            solutions += backtrack(row+1,diagonals,antidiagonals,cols);
            
            cols.erase(col);
            diagonals.erase(currDiag);
            antidiagonals.erase(currAntiDiag);
        }
        return solutions;
    }
    
public:
    int totalNQueens(int n) {
        size = n;
        return backtrack(0, {},{},{});
    }
};