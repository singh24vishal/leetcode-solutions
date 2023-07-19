//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
        vector<int> vis(n,0);
        bool flag=false;
        vector<int> ind(n,0);
        queue<int> temp;
        for(int i=0;i<n;i++)
        {
            for(auto e:adj[i]) ind[e]++;
        }
        for(int i=0;i<n;i++)
        {
            if(ind[i]==0) temp.push(i);
        }
        while(!temp.empty())
        {
            int v=temp.front();
            temp.pop();
            vis[v]=1;
            for(auto e:adj[v])
            {
                ind[e]--;
                if(ind[e]==0) temp.push(e);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0) flag=true;
        }
        return flag;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends