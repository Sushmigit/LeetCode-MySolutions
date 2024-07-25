class Solution {
public:
    //TC->O(n*m) SC->O(n)
    int coinChange(vector<int>& coins, int amount) {
        if(amount<1)
            return 0;
     vector<int>mincoins(amount+1,INT_MAX);
        mincoins[0]=0;
        for(int i=1;i<=amount;i++)
        {
            for(auto coin:coins)
            {
                if(coin<=i && mincoins[i-coin]!=INT_MAX)
                {
                    mincoins[i] = min(mincoins[i],1+mincoins[i-coin]);
                }
            }
        }
        if(mincoins[amount]==INT_MAX)
            return -1;
        return mincoins[amount];
    }
};