class Solution {
public:
    bool find132pattern(vector<int>& v) {
        int n=v.size();
        stack<int> st;
        int x=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            if(v[i]<x) return true;
            while(!st.empty() and v[i]>st.top())
            {
                x=st.top();
                st.pop();
            }
            st.push(v[i]);
        }
        return false;
    }
};