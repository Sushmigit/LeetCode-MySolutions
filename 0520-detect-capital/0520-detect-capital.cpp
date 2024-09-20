class Solution {
public:
    bool detectCapitalUse(string word) {
        char first = word[0];
        int n = word.size();
        int fcap = -1,cap = 0,lower = 0;
        if(first >= 'A' && first <= 'Z')
            fcap = 1;
        for(int i=1;i<word.size();i++)
        {
            if(word[i] <= 'Z' && word[i] >= 'A')
                cap++;
            else
                lower++;
        }
        if(fcap != -1)
        {
            if(cap == n-1 || lower == n-1)
                return true;
        }
        if(fcap == -1 && lower == n-1)
            return true;
            return false;
    }
};