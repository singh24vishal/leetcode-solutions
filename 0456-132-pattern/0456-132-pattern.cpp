class Solution {
public:
    bool find132pattern(vector<int>& v) {
        multiset<int> st1,st2;
        int n=v.size();
        for(int i=1;i<n;i++) st2.insert(v[i]);
        st1.insert(v[0]);
        for(int i=1;i<n;i++)
        {
            st2.erase(st2.find(v[i]));
            auto it=st2.lower_bound(v[i]);
            if(it!=st2.begin())
            {
                it--;
                if(*st1.begin()<*it)
                {
                    cout<<i<<" "<<v[i];
                    return true;
                }
            }
            st1.insert(v[i]);
        }
        return false;
    }
};