class Solution {
public:
    int fun(int i,vector<int>&rods,int diff,vector<unordered_map<int,int>>&dp,int n)
    {
        if(i==n)
        {
            if(diff==0) return 0;
            return INT_MIN;
        }
        if(dp[i].find(diff)!=dp[i].end()) return dp[i][diff];
        int a=fun(i+1,rods,diff,dp,n);
        int b=rods[i]+fun(i+1,rods,diff+rods[i],dp,n);
        int c=fun(i+1,rods,diff-rods[i],dp,n);
        return dp[i][diff]=max({a,b,c});
    }
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        vector<unordered_map<int,int>> dp(n);
        return fun(0,rods,0,dp,n);
    }
};