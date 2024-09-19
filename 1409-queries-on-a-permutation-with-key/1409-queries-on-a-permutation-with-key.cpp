class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int>ans;
        deque<int>p;
        for(int i=0;i<m;i++)
            p.push_back(i+1);
        for(int q:queries)
        {
            int pos = 0;
            for(int i=0;i<m;i++)
            {
                if(p[i] == q)
                {
                    pos = i;
                    break;
                }
            }
            ans.push_back(pos);
            p.erase(p.begin() + pos);
            p.push_front(q);
        }
        return ans;
    }
};