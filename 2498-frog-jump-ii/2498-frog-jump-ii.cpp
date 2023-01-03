class Solution {
public:
    int maxJump(vector<int>& v) {
        int n=v.size();
        int ans=-1;
        ans=max(ans,v[1]-v[0]);
        ans=max(ans,v[n-1]-v[n-2]);
        for(int i=2;i<n;i++)
        ans=max(ans,v[i]-v[i-2]);
        return ans;
    }
};