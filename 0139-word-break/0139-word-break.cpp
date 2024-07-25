class Solution {
public:
    bool helper(int start,string s,vector<string>& wordDict,vector<int>& memo)
    {
        if(start == s.size())
            return true;
        if(memo[start]!=-1)
            return memo[start];
        for(int end = start+1;end<=s.size();end++)
        {
            string str = s.substr(start,end-start);
            if(find(wordDict.begin(),wordDict.end(),str)!=wordDict.end())
            {
                if(helper(end,s,wordDict,memo))
                    return memo[start]=true;
            }
        }
        return memo[start]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
      vector<int>memo(s.size(),-1);
      return helper(0,s,wordDict,memo);
    }
};