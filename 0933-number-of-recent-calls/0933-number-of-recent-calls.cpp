class RecentCounter {
public:
    stack<int>st;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        stack<int>inner = st;
        int s = t - 3000;
        int e = t;
        int cnt = 0;
        while(!inner.empty() && (inner.top() >= s && inner.top() <= e))
              {
                  cnt++;
                  inner.pop();
              }
              cnt+=1;
              st.push(t);
              return cnt;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */