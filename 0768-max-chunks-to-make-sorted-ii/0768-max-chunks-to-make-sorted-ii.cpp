class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
        int ans=0,n=v.size();
        multiset<int> st,st2;
        for(int i=0;i<n;i++) st.insert(v[i]);
        
        for(int i=0;i<n;i++)
        {
            st.erase(st.find(v[i]));
            st2.insert(v[i]);
            if(st.size()==0 or (*st.begin()>=v[i] and *st.begin()>=*--st2.end())) ans++;
        }
        return ans;
    }
};