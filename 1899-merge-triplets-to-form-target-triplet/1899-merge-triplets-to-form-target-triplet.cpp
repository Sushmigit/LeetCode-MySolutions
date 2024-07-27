class Solution {
public:
//TC->O(n) SC->O(1)
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int>good;
        for(auto& it:triplets)
        {
            //If any of the value in the triplet > corresponding value in target
            //We can't combine that triplet with anyother to get ans
            //Skip it
            if(it[0]>target[0] || it[1]>target[1] || it[2]>target[2])
            continue;
           
           //otherwise check the value of triplet with corresponding value of target
           //If matches insert it to good
            for(int i=0;i<3;i++)
            {
                if(it[i]==target[i])
                good.insert(i);//Insert the index not the value
                //if the target [5,5,5] inserting value won't be crt
            }
        }
        return good.size()==3;
    }
};
