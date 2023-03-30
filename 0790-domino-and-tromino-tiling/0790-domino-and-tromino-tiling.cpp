class Solution {
public:
    int numTilings(int n) {
        vector<int> dp(n+4);
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        int mod=1e9+7;
        if(n<=3) return dp[n];
        for(int i=4;i<=n;i++) dp[i]=((2*dp[i-1])%mod+dp[i-3])%mod;
        return dp[n];
    }
};