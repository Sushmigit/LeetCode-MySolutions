class Solution {
public:
    //TC->O(n*m*4^k) where k->length of the word  
//For each char in word we are exploring all the four directions so 4^k 
//SC->O(k) depth of recursion
   bool solve(int ind,int i,int j,vector<vector<char>>& board, string word,int n,int m)
   {
       if(i<0 || i>=n || j<0 || j>=m || board[i][j]!=word[ind])
       return false;

       if(ind == word.size()-1)
       return true;

       board[i][j]='#';

       if(solve(ind+1,i-1,j,board,word,n,m)||  //up
          solve(ind+1,i+1,j,board,word,n,m)||  //down
          solve(ind+1,i,j-1,board,word,n,m)||  //left
          solve(ind+1,i,j+1,board,word,n,m))   //right
          return true;

          board[i][j]=word[ind];
          return false;
   }
    bool exist(vector<vector<char>>& board, string word) {
         int n = board.size();
        int m = board[0].size();
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(solve(0,i,j,board,word,n,m))
                    return true;
                }
            }
        }
        return false;
    }
};