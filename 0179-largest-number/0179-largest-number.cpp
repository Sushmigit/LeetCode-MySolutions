class Solution {
public:
    static bool comp(string &a,string &b)
    {
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        string str = "";
        int n = nums.size();
        vector<string>arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back(to_string(nums[i]));
        }
       sort(arr.begin(),arr.end(),comp);
        if(arr[0] == "0") return "0";
        for(int i=0;i<arr.size();i++)
            str += arr[i];
        return str;
    }
};