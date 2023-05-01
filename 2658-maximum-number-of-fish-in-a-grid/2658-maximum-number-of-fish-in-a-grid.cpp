class Solution {
public:
    vector<pair<int,int>> vp={{0,1},{0,-1},{1,0},{-1,0}};
    bool valid(int i,int j,int n,int m)
    {
        return (i>=0 and j>=0 and i<n and j<m);
    }
    void fun(vector<vector<int>>&grid,int i,int j,int &temp,int n,int m)
    {
        temp+=grid[i][j];
        grid[i][j]=0;
        for(auto e:vp)
        {
            int x=i+e.first,y=j+e.second;
            if(valid(x,y,n,m) and grid[x][y]>0) fun(grid,x,y,temp,n,m);
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]>0)
                {
                    int temp=0;
                    fun(grid,i,j,temp,n,m);
                    ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};