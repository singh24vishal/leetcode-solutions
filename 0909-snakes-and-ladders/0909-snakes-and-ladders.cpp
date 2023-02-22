class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& v) {
        int n=v.size();
        vector<int> dis(n*n,-1);
        vector<int> temp(n*n);
        int c=0,f=1;
        for(int i=n-1;i>=0;i--)
        {
            if(!f)
            {
                for(int j=n-1;j>=0;j--) temp[c++]=v[i][j];
            }
            else 
            {
                for(int j=0;j<n;j++) temp[c++]=v[i][j];
            }
            f=!f;
        }
        queue<int> q;
        q.push(0);
        dis[0]=0;
        while(!q.empty())
        {
            int j=q.front();
            q.pop();
            if(j==n*n-1) return dis[j];
            for(int i=1;i<=6 and j+i<n*n;i++)
            {
                int k=j+i;
                if(temp[k]!=-1) k=temp[k]-1;
                if(dis[k]==-1)
                {
                    dis[k]=dis[j]+1;
                    q.push(k);
                }
            }
        }
        return -1;
    }
};