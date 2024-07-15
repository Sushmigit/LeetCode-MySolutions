class Solution {
public:
    //TC->O(N*M) SC->O(N*M)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int i;
        vector<int>ans;
        int left = 0, right = m-1, top = 0, bottom = n-1;
        while(top<=bottom && left<=right)
        {
            //Right
            for(i=left;i<=right;i++)
                ans.push_back(matrix[top][i]);
            top++;
            
            //Bottom
            for(i=top;i<=bottom;i++)
                ans.push_back(matrix[i][right]);
            right--;
            
            //Left
            if(top<=bottom)
            {
                for(i=right;i>=left;i--)
                ans.push_back(matrix[bottom][i]);
            bottom--;
            }
            //Top
            if(left<=right)
            {
                for(i=bottom;i>=top;i--)
                ans.push_back(matrix[i][left]);
            left++;
            }
            
        }
        return ans;
    }
};