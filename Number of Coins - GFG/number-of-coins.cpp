//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int n, int sum) 
	{ 
	    // Your code goes here
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

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends