class Solution {
public:
//TC->O(n) SC->O(1)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas=0,total_cost=0;
        int start = 0;
        for(int g:gas)
        total_gas+=g;
        for(int c:cost)
        total_cost+=c;
        if(total_gas<total_cost) return -1;
        int cur_fuel = 0;
        for(int i=0;i<gas.size();i++)
        {
            cur_fuel += (gas[i]-cost[i]);
            if(cur_fuel<0) //when cur_fuel<0, we can't reach the next station so we start the circuit from the next index
            {
                cur_fuel = 0;
                start = (i+1);
            }
        }
        return start;
    }
};
