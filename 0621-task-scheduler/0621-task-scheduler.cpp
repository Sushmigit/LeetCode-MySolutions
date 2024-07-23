class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //TC->O(T*n) in the worst case every task has to wait for cooldown time SC->O(T)
        int time = 0;
        priority_queue<int>pq;
        queue<pair<int,int>>q;
        unordered_map<char,int>count;
        for(char task:tasks)//O(T)
        {
            count[task]++;
        }
        for(auto &entry:count)//O(u log u)=>O(1) where u=26
        {
            pq.push(entry.second);
        }
        while(!pq.empty() || !q.empty())//O(T*n)
        {
            //if the cur_time>=cooldown expiry time
            if(!q.empty() && time>=q.front().second)
            {
                pq.push(q.front().first);
                q.pop();
            }
            //Execute the tasks
            if(!pq.empty())
            {
                int cnt = pq.top()-1;//Since executing the task,decrement cnt by 1
                pq.pop();
                if(cnt>0) //If the same kind of task is remaining, it has to wait for the completion of the cooldown time
                    q.push({cnt,time+n+1});
            }
            time++;
        }
        return time;
    }
};