class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)
            return true;
        int l = 1;
        int r = num/2;
        while(l<=r)
        {
            int mid = (l+r)/2;
            long long sq = static_cast<long long> (mid)*mid;
            if(sq == num)
                return true;
            else if(num < sq)
                r = mid-1;
            else
                l=mid+1;
        }
        return false;
    }
};