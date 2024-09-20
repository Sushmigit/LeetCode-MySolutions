class Solution {
public:
    int countBinarySubstrings(string s) {
        int cnt = 0;int cur = 1,prev = 0;
        int n =s.size();
        for(int i=1;i<n;i++)
        {
           if(s[i] == s[i-1]) cur++;
            else
            {
                cnt+=min(prev,cur);
                prev = cur;
                cur = 1;
            }
        }
        cnt+=min(prev,cur);
        return cnt;
    }
        
};