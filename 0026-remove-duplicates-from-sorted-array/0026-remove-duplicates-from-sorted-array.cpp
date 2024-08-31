class Solution {
public:
    int brute(vector<int>& arr)
    {
        set<int>st(arr.begin(),arr.end());
        int ind = 0;
        for(auto it : st)
        {
            arr[ind++] = it;
        }
        return ind;
    }
    int twoPointer(vector<int>& arr)
    {
        /*int i = 0,j;
        int n = arr.size();
       for(int j=i+1;j<n;j++)
       {
           if(arr[j]!=arr[i])
           {
               i++;
               arr[i] = arr[j];
           }
       }
        return i;*/
        int i = 1;
int n = arr.size();
for(int j = 1; j < n; j++)
{
    if(arr[j] != arr[j-1])
    {
       
        arr[i++] = arr[j];
    }
}
        return i;
    }
    int removeDuplicates(vector<int>& arr) {
        //return brute(arr);
          return twoPointer(arr);
    }
};