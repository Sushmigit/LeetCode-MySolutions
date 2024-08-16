class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        int bp = 0;
        if(n < 3)
            return false;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i] < arr[i+1])
                bp = i+1;
            else if(arr[i] >= arr[i+1])
                break;
        }
        if(bp == n-1 || bp == 0)
            return false;
        for(int i=bp;i<n-1;i++)
        {
            if(arr[i] <= arr[i+1])
                return false;
        }
        return true;
    }
};