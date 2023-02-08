class Solution {
public:
    int coinChange(vector<int>& coins, int sum) {
        int n=coins.size();
        vector<int> dp(sum+1,INT_MAX-1);
        dp[0]=0;
        for(int i=1;i<=sum;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(coins[j]<=i) dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }
        if(dp[sum]>sum) return -1;
        return dp[sum];
    }
};