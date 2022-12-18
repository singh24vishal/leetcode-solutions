class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        vector<int> ans;
        multiset<int> st;
        int i=0,j=k-1,n=v.size();
        for(int x=i;x<=j;x++) st.insert(v[x]);
        while(j<n)
        {
            ans.push_back(*(--st.end()));
            st.erase(st.find(v[i]));
            i++;
            j++;
            if(j<n) st.insert(v[j]);
        }
        return ans;
    }
};