class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
        int m = magazine.size();
        int total_char = n;
        map<char,int>mpp;
        for(int i=0;i<m;i++)
            mpp[magazine[i]]++;
        for(int i=0;i<n;i++)
        {
            if(mpp[ransomNote[i]] > 0)
            {
                total_char--;
                mpp[ransomNote[i]]--;
            }
        }
        return total_char == 0;
    }
};