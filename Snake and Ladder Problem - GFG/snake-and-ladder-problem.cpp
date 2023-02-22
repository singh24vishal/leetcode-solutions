//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int n, int arr[]){
        // code here
        map<int,int> mp;
        for(int i=1;i<=30;i++) mp[i]=i;
        for(int i=0;i<2*n;i+=2) mp[arr[i]]=arr[i+1];
        vector<int> vis(31,0);
        queue<pair<int,int>> q;
        q.push({0,1});
        vis[1]=1;
        int ans;
        while(!q.empty())
        {
            pair<int,int> temp=q.front();
            int i=temp.first,j=temp.second;
            q.pop();
            if(j==30) 
            {
                ans=i;
                break;
            }
            for(int k=1;k<=6 and k+j<=30;k++)
            {
                int x=j+k;
                x=mp[x];
                if(vis[x]) continue;
                vis[x]=1;
                q.push({i+1,x});
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends