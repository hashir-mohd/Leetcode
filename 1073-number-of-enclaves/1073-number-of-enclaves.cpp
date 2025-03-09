class Solution {
    void dfs(vector<vector<int>>& board,int row, int col){
        int n=board.size();
        int m=board[0].size();
        board[row][col]=2;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        for(int d=0;d<4;d++){
            int nrow=row+dx[d];
            int ncol=col+dy[d];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]==1){
                dfs(board,nrow,ncol);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if((row==0 || row==n-1 || col==0 || col==m-1) && board[row][col]==1){
                    dfs(board,row,col);
                }
            }
        }
        int enclaves=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(board[row][col]==1){
                    enclaves++;
                }
                
            }
        }
        return enclaves;
    }
};