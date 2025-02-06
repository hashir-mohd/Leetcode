using vi = vector<int>;           
using vvi = vector<vector<int>>; 

class Solution {
public:
    
    void ans(vvi &matrix, vector<vector<string>> &res) {
        vector<string> board;
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            string rowStr;
            for (int j = 0; j < n; j++) {
                rowStr += (matrix[i][j] == 1) ? 'Q' : '.';
            }
            board.push_back(rowStr);
        }
        res.push_back(board);
    }

    bool check(vvi &matrix, int row, int col) {
        int n = matrix.size();
        // Check for column
        for (int i = 0; i < row; i++) {
            if (matrix[i][col] == 1) return false;
        }
        // Check for upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (matrix[i][j] == 1) return false;
        }
        // Check for upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (matrix[i][j] == 1) return false;
        }
        return true;
    }

    void solve(vvi &matrix,int row,vector<vector<string>> &res){
        if(row==matrix.size()){
            ans(matrix,res);
            return;
        }
        for(int col = 0; col< matrix.size();col++){
            if (check(matrix, row, col)) {  
                matrix[row][col] = 1; 
                solve(matrix, row + 1, res);
                matrix[row][col] = 0; 
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vvi matrix(n,vi(n,0));
        vector<vector<string>> res;
        solve(matrix, 0,res);
        return res;
    }
};