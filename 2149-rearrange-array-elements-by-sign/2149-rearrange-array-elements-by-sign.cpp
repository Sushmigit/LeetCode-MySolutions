class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        //TC->O(n) SC->O(n)
         int n = a.size();
    int pos = 0 ,neg = 1;
     vector<int>ans(n);
    for(int i=0;i<n;i++)
    {
       if (a[i] >= 0) {
        ans[pos] = a[i];
        pos += 2;
       } else if (a[i] < 0) {
        ans[neg] = a[i];
        neg+=2;
       }
    }
    return ans;
    }
};