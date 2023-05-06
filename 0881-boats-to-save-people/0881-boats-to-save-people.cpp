class Solution {
public:
    int numRescueBoats(vector<int>& v, int l) {
        multiset<int> st;
        int ans=0;
        for(auto e:v) st.insert(e);
        while(st.size()>0)
        {
            int x=*st.begin();
            st.erase(st.begin());
            int y=l-x;
            if(st.size()>0)
            {
                auto it=st.upper_bound(y);
                if(it!=st.begin())
                {
                    it--;
                    st.erase(it);
                }
            }
            ans++;
        }
        return ans;
    }
};