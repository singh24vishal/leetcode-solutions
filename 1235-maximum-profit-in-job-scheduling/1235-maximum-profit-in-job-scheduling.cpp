class Solution {
public:
    int fun(vector<vector<int>>&v,vector<int>&dp,int n,int i)
    {
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        vector<int> f={v[i][1],0,0};
        int it=lower_bound(v.begin(),v.end(),f)-v.begin();
        return dp[i]=max(v[i][2]+fun(v,dp,n,it),fun(v,dp,n,i+1));
    }
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        int n=s.size();
        vector<vector<int>> v;
        for(int i=0;i<n;i++) v.push_back({s[i],e[i],p[i]});
        sort(v.begin(),v.end());
        vector<int> dp(n,-1);
        return fun(v,dp,n,0);
    }
};