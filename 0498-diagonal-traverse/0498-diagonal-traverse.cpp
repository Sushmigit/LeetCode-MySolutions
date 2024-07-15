class Solution {
public:
    //TC->O(N) where N is the total no of ele SC->O(N*M) for returning the ans
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
       int n = mat.size();
        int m = mat[0].size();
        int row=0,col=0;
        bool up = true;
        vector<int>ans;
        while(row<n && col<m)
        {
            if(up)//Diagonal is moving up
            {
                while(row>0 && col<m-1)
                {
                    ans.push_back(mat[row][col]);
                    row--;
                    col++;
                }
                ans.push_back(mat[row][col]);
                if(col == m-1)
                    row++;
                else
                    col++;
            }
            else//Diagonal is moving down
            {
                while(row<n-1 && col>0)
                {
                    ans.push_back(mat[row][col]);
                    row++;
                    col--;
                }
                ans.push_back(mat[row][col]);
                if(row == n-1)
                    col++;
                else
                    row++;
            }
            up=!up;
        }
        return ans;
    }
};