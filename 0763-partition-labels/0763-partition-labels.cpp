class Solution {
public:
//TC->O(n) SC->O(26)
    vector<int> partitionLabels(string s) {
       int n = s.size();
       unordered_map<char,int>mpp;//{char,last_index}
       for(int i=0;i<n;i++)
       {
        mpp[s[i]] = i;
       } 
       vector<int>ans;
       int size = 0,end = 0;
       for(int i=0;i<n;i++)
       {
        size+=1;
        end = max(end,mpp[s[i]]);//To find the end of a partition
        if(i==end)//Start new partition
        {
            ans.push_back(size);
            size = 0;
        }
       }
       return ans;
    }
};
