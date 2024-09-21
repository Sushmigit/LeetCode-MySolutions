class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mpp;
        int n = s.size();
        for(int i=0;i<s.size();i++)
            mpp[s[i]]++;
        int cnt = 0;
        for(auto it:mpp)
        {
            if(it.second % 2 == 0)
                cnt+=it.second;
            else if(it.second / 2 >= 1)
                cnt+=(it.second / 2 * 2);
        }
        if(cnt < n) cnt++;
        return cnt;
    }
};