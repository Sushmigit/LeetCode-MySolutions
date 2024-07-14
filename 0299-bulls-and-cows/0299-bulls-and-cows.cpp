class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0,cows = 0;
        int i;
        vector<int>hash(10,0);
        int n = secret.size();
        for(i=0;i<n;i++)
        {
            int s = secret.at(i)-'0';
            int g = guess.at(i)-'0';
            if(s==g)
                bulls++;
            //In hash for secret string char increment the fre
            //In hash for guess string char decrement the fre
            //In any case if secret fre < 0 => it is already appeared previously in guess
            //In any case if guess fre > 0 => it is already appeared previously in secret
            //In the above two cases incre cows
            //the digits are appearing but in wrong pos in guess
            else
            {
                if(hash[s]++<0)cows++; 
                if(hash[g]-->0)cows++; 
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};