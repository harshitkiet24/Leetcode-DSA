class Solution {
public:
    bool IsValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (i != col && board[row][i] == c) {
                return false;
            }
            if (i!= row && board[i][col] == c) {
                return false;
            }
            int r = 3 * (row / 3) + (i / 3);
            int cc = 3 * (col/3) + (i%3);
            if ((r!=row || cc!=col) && board[r][cc] == c) {
                return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0;j < 9;j++){
                if(board[i][j] != '.'){
                    char c = board[i][j];
                    if(IsValid(board,i,j,c)==false){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};