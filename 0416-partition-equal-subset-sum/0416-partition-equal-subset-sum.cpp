class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i=0;i<n;i++)
            sum+=arr[i];
        if(sum % 2 == 1)
            return false;
        int k = sum/2;
         vector<bool>prev(k+1,false),cur(k+1,false);
    prev[0] = cur[0] = true;
    if(arr[0] <= k)
    prev[arr[0]] = true;
    int tar;
    for(int ind = 1;ind < n;ind++)
    {
        for(tar = 1;tar <= k;tar++)
        {
             bool notTake = prev[tar];
             bool take = false;
             if(arr[ind] <= tar)
             take = prev[tar - arr[ind]];
             cur[tar] = (take || notTake);
        }
        prev = cur;
    }
    return prev[k];
    }
};