class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
      set<int>st(arr.begin(),arr.end());
        int ind = 0;
        for(auto it : st)
        {
            arr[ind++] = it;
        }
        return ind;
    }
};