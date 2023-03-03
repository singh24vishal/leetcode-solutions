class Solution {
public:
    int maximalSquare(vector<vector<char>>& v) {
        int n=v.size(),m=v[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0)),up(n,vector<int>(m,1)),down(n,vector<int>(m,1));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(v[i][j]=='0') dp[i][j]=0;
                else dp[i][j]=dp[i][j+1]+1;
            }
        }
        for(int j=0;j<m;j++)
        {
            stack<int> s1,s2;
            for(int i=0;i<n;i++)
            {
                while(s1.size()>0 and dp[s1.top()][j]>=dp[i][j]) s1.pop();
                if(s1.size()==0) up[i][j]=i+1;
                else up[i][j]=i-s1.top();
                s1.push(i);
            }
            for(int i=n-1;i>0;i--)
            {
                while(s2.size()>0 and dp[s2.top()][j]>=dp[i][j]) s2.pop();
                if(s2.size()>0) down[i][j]=s2.top()-i;
                else down[i][j]=n-i;
                s2.push(i);
            }   
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int k=min(dp[i][j],up[i][j]+down[i][j]-1);
                ans=max(ans,k*k);
            }
        }
        return ans;
    }
};