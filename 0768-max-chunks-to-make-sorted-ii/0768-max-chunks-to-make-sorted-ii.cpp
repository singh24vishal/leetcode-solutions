class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
        int ans=0,n=v.size(),l=-1;
        vector<int> r(n+1,INT_MAX);
        for(int i=n-1;i>=0;i--) r[i]=min(r[i+1],v[i]);
        for(int i=0;i<n;i++)
        {
            l=max(l,v[i]);
            if(l<=r[i+1]) ans++;
        }
        return ans;
    }
};