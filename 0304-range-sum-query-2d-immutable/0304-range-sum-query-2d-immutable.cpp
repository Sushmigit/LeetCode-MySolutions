class NumMatrix {
public:
    vector<vector<int>>mat;
    NumMatrix(vector<vector<int>>& matrix) {
       int n =matrix.size();
        int m = matrix[0].size();
        mat=vector<vector<int>>(n+1,vector<int>(m+1,0));
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {     //cur value in matrix+top value+left value-common value in left and top
                mat[i][j]=matrix[i-1][j-1]+mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
    row1++;col1++;row2++;col2++;
        //total val in cur mat - top sum value from start - left sum value from start + diagonal value which is sub twice => sum of given rect
        return mat[row2][col2]-mat[row1-1][col2]-mat[row2][col1-1]+mat[row1-1][col1-1];
    }
    
       
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */