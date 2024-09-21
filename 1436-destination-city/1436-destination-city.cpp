class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string,int>mpp;
        string ans = "";
        int n = paths.size();
        for(int i=0;i<n;i++)
        {
            mpp[paths[i][0]]++;
            if(mpp.find(paths[i][1]) == mpp.end())
            mpp[paths[i][1]] = 0;
        }
        for(auto it:mpp)
        {
            if(it.second == 0)
            {
                ans = it.first;
                break;
            }
        }
        return ans;
    }
};