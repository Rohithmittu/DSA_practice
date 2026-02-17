class Solution {
public:

    bool issafe(vector<vector<char>>& board, int row, int col,char dig){
        for(int i = 0;i<9;i++){
            if(board[row][i] == dig){
                return false;
            }
        }
        for(int i = 0;i<9;i++){
            if(board[i][col] == dig){
                return false;
            }
        }

        int srow = (row/3) * 3;
        int scol = (col /3) * 3;

        for(int i = srow;i<=srow+2;i++){
            for(int j = scol;j<=scol+2;j++){
                if(board[i][j] == dig){
                    return false;
                }
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board, int row, int col){
        
        if(row == 9){
            return true;
        }

        int newrow = row, newcol = col+1;
        if(newcol == 9){
            newrow = row+1;
            newcol = 0;
        }

        if(board[row][col] != '.'){
            return solve(board,newrow,newcol);
        }

        for(char i = '1';i<='9';i++){
            if(issafe(board,row,col,i)){

                board[row][col] = i;

                if(solve(board,newrow,newcol)){
                    return true;
                }

                board[row][col] = '.';

            }


        }

        return false;


    }

    void solveSudoku(vector<vector<char>>& board) {

        solve(board,0,0);

    }
};