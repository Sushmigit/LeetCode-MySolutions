class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       int n = digits.size();
        for(int i=n-1;i>=0;i--)
        {
            if(digits[i]<9)//less than 9 just add 1
            {
                digits[i]++;
                return digits;
            }
            else //make cur digit place as 0
                digits[i]=0;
        }
        digits.insert(digits.begin(),1);//if all the digits are 9,insert 1 at beginning
        return digits;
    }
};
