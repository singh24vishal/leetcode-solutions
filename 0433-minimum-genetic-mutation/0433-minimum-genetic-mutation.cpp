class Solution {
public:
    bool ok(string &st,string &en)
    {
        int t=0;
        for(int i=0;i<8;i++)
        {
            if(st[i]!=en[i]) t++;
        }
        return t==1;
    }
    int minMutation(string st, string en, vector<string>& v) {
        int n=v.size();
        vector<int> vis(n,0);
        queue<pair<string,int>> q;
        q.push({st,0});
        while(!q.empty())
        {
            pair<string,int> p=q.front();
            q.pop();
            string temp=p.first;
            int op=p.second;
            if(temp==en) return op;
            for(int i=0;i<n;i++)
            {
                if(vis[i]==0 and ok(temp,v[i]))
                {
                    vis[i]=1;
                    q.push({v[i],op+1});
                }
            }
        }
        return -1;
    }
};