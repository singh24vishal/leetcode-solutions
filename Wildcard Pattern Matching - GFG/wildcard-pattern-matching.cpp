//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    
    static int fun(int i,int j,vector<vector<int>>&dp,string&s,string&p)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==0)
        {
            if(j==0) return dp[i][j]=1;
            else
            {
                if(p[j-1]=='*') return dp[i][j]=fun(i,j-1,dp,s,p);
                else return dp[i][j]=0;
            }
        }
        if(j==0)
        {
            if(i==0) return dp[i][j]=1;
            else return dp[i][j]=0;
        }
        int ans=0;
        if(s[i-1]==p[j-1] or p[j-1]=='?')
            ans=ans or fun(i-1,j-1,dp,s,p);
        else if(p[j-1]=='*')
        {
            for(int k=i;k>=0;k--)
            {
                ans=ans or fun(k,j-1,dp,s,p);
            }
        }
        else ans=0;
        return dp[i][j]=ans;
    }

    int wildCard(string p,string s)
    {
        int n=s.size(),m=p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return fun(n,m,dp,s,p);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends