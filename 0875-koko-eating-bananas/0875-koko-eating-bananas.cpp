class Solution {
public:
    //TC->O(n log m) SC->O(1)
    int maxi(vector<int>& piles)
    {
        int maxi = 0;
        for(int i=0;i<piles.size();i++)
            maxi = max(maxi,piles[i]);
        return maxi;
    }
       long long func(vector<int>& piles, int bphr)
    {
         long long total_hrs = 0;
        for(int i=0;i<piles.size();i++)
        {
             int val = (piles[i] + bphr - 1) / bphr;
            total_hrs+=val;
        }
        return total_hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=maxi(piles);int mid;
        while(low<=high)
        {
            mid = low+(high-low)/2;
            long long hrs = func(piles,mid);
            if(hrs<=h)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};