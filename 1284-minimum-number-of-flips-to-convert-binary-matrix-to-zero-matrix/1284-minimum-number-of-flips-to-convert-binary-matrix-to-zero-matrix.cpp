class Solution {
public:
    vector<pair<int,int>> vp={{1,0},{-1,0},{0,1},{0,-1}};
    bool check(vector<vector<int>>&temp)
    {
        for(int i=0;i<temp.size();i++)
        {
            for(int j=0;j<temp[0].size();j++)
            {
                if(temp[i][j]) return false;
            }
        }
        return true;
    }
    int minFlips(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        map<vector<vector<int>>,int> mp;
        queue<vector<vector<int>>> q;
        q.push(v);
        mp[v]=1;
        int ans=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                if(check(q.front())) return ans;
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<m;j++)
                    {
                        vector<vector<int>> temp=q.front();
                        temp[i][j]=1-temp[i][j];
                        for(auto [x,y]:vp)
                        {
                            int xx=i+x,yy=y+j;
                            if(xx>=0 and xx<n and yy>=0 and yy<m) temp[xx][yy]=1-temp[xx][yy];
                        }
                        if(!mp[temp])
                        {
                            mp[temp]=1;
                            q.push(temp);
                        }
                    }
                }
                q.pop();
            }
            ans++;
        }
        return -1;
    }
};