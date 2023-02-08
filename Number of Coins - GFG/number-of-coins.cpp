//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int n, int sum) 
	{ 
	    // Your code goes here
        int t[n+1][sum+1];
        for(int i=0;i<=sum;i++)
            t[0][i]=INT_MAX-1;
        for(int i=1;i<=n;i++)
            t[i][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(coins[i-1]<=j)
                    t[i][j]=min(1+t[i][j-coins[i-1]],t[i-1][j]);
                else t[i][j]=t[i-1][j];
            }
        }
        if(t[n][sum]>sum)
            return -1;
        return t[n][sum];
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