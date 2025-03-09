class Solution {
public:
    void dfs(vector<vector<char>>& board,int row, int col){
        int n=board.size();
        int m=board[0].size();
        board[row][col]='1';
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        for(int d=0;d<4;d++){
            int nrow=row+dx[d];
            int ncol=col+dy[d];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O'){
                dfs(board,nrow,ncol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if((row==0 || row==n-1 || col==0 || col==m-1) && board[row][col]=='O'){
                    dfs(board,row,col);
                }
            }
        }
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(board[row][col]=='O'){
                    board[row][col]='X';
                }
                else if(board[row][col]=='1'){
                    board[row][col]='O';
                }
            }
        }
        

    }
};