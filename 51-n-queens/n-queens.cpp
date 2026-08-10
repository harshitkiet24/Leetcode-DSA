class Solution {
public:

    void solve(int col, vector<string>& board, vector<vector<string>> & ans, vector<int> &lr, vector<int> &ud,vector<int> &ld,int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for(int i = 0;i< n;i++){
            if(lr[i] == 0 && ud[(n-1) + (col - i)] == 0 && ld[col + i] == 0){
                lr[i] = 1;
                ud[(n-1) + (col -i)] = 1;
                ld[col + i] = 1;
                board[i][col] = 'Q';
                solve(col+1,board,ans,lr,ud,ld,n);
                lr[i] = 0;
                ud[(n-1) + (col -i)] = 0;
                ld[col + i] = 0;
                board[i][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        vector<int> lr(n,0);
        vector<int> ud(2*n - 1,0);
        vector<int> ld(2*n - 1,0);
        string s(n, '.');

        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        solve(0, board, ans,lr,ud,ld ,n);
        return ans;
    }
};