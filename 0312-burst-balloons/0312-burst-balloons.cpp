class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int g=0;g<n;g++)
        {
            for(int i=0,j=g;j<n;i++,j++)
            {
                int val=INT_MIN;
                for(int k=i;k<=j;k++)
                {
                    int x=1,y=nums[k],z=1;
                    if(i!=0) x=nums[i-1];
                    if(j!=n-1) z=nums[j+1];
                    int cost=x*y*z;
                    int c1=0,c2=0;
                    if(i!=k) c1=dp[i][k-1];
                    if(k!=j) c2=dp[k+1][j];
                    val=max(val,c1+c2+cost);
                }
                dp[i][j]=val;
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++) cout<<dp[i][j]<<" "; cout<<endl;
        // }
        return dp[0][n-1];
    }
};