class Solution {
public:
    //Tc->O(81*27)->O(1) SC->O(1)
    bool isValid(int r,int c,char val,vector<vector<char>>& board)
    {
        //O(9+9+9)->O(27)
        for(int i=0;i<9;i++)
        {
            if(board[i][c]==val && i!=r) return false;//Check the Column
            if(board[r][i]==val && i!=c) return false;//Check the row
            int row = (r/3)*3+i/3,col = (c/3)*3+i%3;
            if(row!=r && col!=c && board[row][col]==val) return false;//Check the Grid
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int i,j;
        //TC->O(9*9)
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(isValid(i,j,board[i][j],board)==false)
                        return false;
                }
            }
        }
        return true;
    }
};