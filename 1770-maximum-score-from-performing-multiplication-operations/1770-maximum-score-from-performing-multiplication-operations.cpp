class Solution {
public:
    int maximumScore(vector<int>& a, vector<int>& b) {
        int n=a.size(),m=b.size();
        vector<int> dp(m+1);
        for(int i=0;i<m;i++)
        {
            int x=b[m-1-i];
            for(int j=0;j<m-i;j++) dp[j]=max(x*a[j]+dp[j+1],x*a[j+n-m+i]+dp[j]);
        }
        return dp[0];
    }
};