class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        int n1 = flowerbed.size();
        if(n1 == 1)
        {
            if(flowerbed[0] == 0)
            {
                cnt = 1;
            }
            else 
            cnt = 0;
            
            if(cnt >= n)
                return true;
            else
                return false;
        }
        if(flowerbed[0] == 0 && flowerbed[1] == 0)
        {
            flowerbed[0] = 1;
            cnt++;
        }
            
        if(flowerbed[n1-1] == 0 && flowerbed[n1-2] == 0)
        {
            flowerbed[n1-1] = 1;
            cnt++;
        } 
        for(int i=1;i<n1-1;i++)
        {
            if(flowerbed[i] == 0 && flowerbed[i+1] == 0 && flowerbed[i-1] == 0)
            {
                cnt++;
                flowerbed[i] = 1;
            }
        }
        if(cnt >= n)
            return true;
        return false;
    }
};