class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,1);
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]>'2') dp[i]=dp[i+1];
            else if(s[i]>'0' and s[i]<='2')
            {
                if(i+2<n and s[i+2]=='0') dp[i]=dp[i+1];
                else if(i+1<n)
                {
                    if(s[i+1]=='0' or (s[i+1]>'6' and s[i]=='2')) dp[i]=dp[i+1];
                    else dp[i]=dp[i]=dp[i+2]+dp[i+1];
                }
                else dp[i]=dp[i+1];
            }
            else if(s[i]=='0')
            {
                if((i+1<n and s[i+1]=='0') or i==0 or (i-1>=0 and s[i-1]>'2')) return 0;
                dp[i]=dp[i+1];
            }
        }
        // for(auto e:dp) cout<<e<<" ";
        return dp[0];
    }
};