class Solution {
public:
//TC->O(n log n) SC->O(n)
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int>cnt;
        priority_queue<int,vector<int>,greater<int>>minH;
        int n = hand.size();
        if(n % groupSize != 0) return false;
        for(int c:hand)
        cnt[c]++;
        for(auto& it:cnt)
        {
            minH.push(it.first);
        }
        while(!minH.empty())
        {
            int x = minH.top();
           
            for(int i=x;i<x+groupSize;i++)
            {
                  if(cnt.find(i)==cnt.end())
                  return false;
                  cnt[i]--;
            if(cnt[i]==0)
            {
                if(i!=minH.top())
                return false;
                minH.pop();
            }  
            }
           
           
        }
        return true;
    }
};
