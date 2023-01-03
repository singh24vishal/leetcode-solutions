class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n=v.size(),ans=0,mn=v[0];
        for(int i=1;i<n;i++)
        {
            ans=max(ans,v[i]-mn);
            mn=min(mn,v[i]);
        }
        return ans;
    }
};