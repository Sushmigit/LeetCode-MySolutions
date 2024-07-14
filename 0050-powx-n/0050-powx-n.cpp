class Solution {
public:
    double myPow(double x, long n) {
       double ans = 1.0;
        
        long nn = n;
        if(n<0)
            nn = nn*-1;
        while(nn > 0)
        {
            if(nn % 2 == 0)
            {
                x = x*x;
                nn = nn/2;
            }
            else if(nn % 2 == 1)
            {
                ans = ans*x;
                nn = nn - 1;
            }
        }
        if(n<0)
            ans = 1/ans;
        return ans;
    }
};