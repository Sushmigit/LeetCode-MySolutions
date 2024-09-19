class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a = "",b = "";
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '#')
            {
                if(!st.empty()) st.pop();
            }
            else
            st.push(s[i]);
        }
        while(!st.empty())
        {
            a = a + st.top();
            st.pop();
        }
        for(int i=0;i<t.size();i++)
        {
            if(t[i] == '#')
            {
                if(!st.empty()) st.pop();
            }
            else
            st.push(t[i]);
        }
        while(!st.empty())
        {
            b = b + st.top();
            st.pop();
        }
        return a == b;
    }
};