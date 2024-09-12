class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
      // sort(arr.begin(),arr.end());
        int n = arr.size();
       map<int,int>mpp;
       for(int i=0;i<n;i++)
           mpp[arr[i]] = i;
        for(int i=0;i<n;i++)
        {
            //if(arr[i] == 0) continue;
            int val1 = arr[i]*2;
            if(mpp.find(val1) != mpp.end() && mpp[val1] != i)
                return true;
            if(arr[i]!=0 && arr[i] % 2 == 0)
            {
                 int val2 = arr[i] / 2;
                 if(mpp.find(val2) != mpp.end())
                    return true;
            }
        }
        return false;
    }
};