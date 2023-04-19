class Solution {
public:
    int candy(vector<int>& v) {
        int n=v.size();
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(v[i]>v[i-1]) dp1[i]=dp1[i-1]+1;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(v[i]>v[i+1]) dp2[i]=dp2[i+1]+1;
        }
        for(int i=0;i<n;i++) ans+=max(dp1[i],dp2[i]);
        return ans;
    }
};