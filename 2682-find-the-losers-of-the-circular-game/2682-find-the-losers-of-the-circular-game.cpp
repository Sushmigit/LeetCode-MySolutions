class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int>ans;
        map<int,int>mpp;
        for(int i=1;i<=n;i++)
            mpp[i] = 0;
        bool flag = true;int i = 1,ind = 1;
        while(flag)
        {
            mpp[i]++;
            if(mpp[i] == 2)
            {
                flag = false;
                break;
            }
            i = i + (ind*k);
            if(i > n) i = i % n;
            if(i == 0) i = n;
            ind++;
        }
       
        for(int i=1;i<=n;i++)
        {
            if(mpp[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};