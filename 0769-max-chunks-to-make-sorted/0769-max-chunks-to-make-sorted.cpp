class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
        int ans=0,n=v.size(),mx=-1;
        for(int i=0;i<n;i++)
        {
            mx=max(v[i],mx);
            if(mx==i) ans++;
        }
        return ans;
    }
};