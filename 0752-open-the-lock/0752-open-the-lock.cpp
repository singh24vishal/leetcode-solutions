class Solution {
public:
    int openLock(vector<string>& dead, string tar) {
        set<string> s;
        for(auto e:dead) s.insert(e);
        if(s.find("0000")!=s.end()) return -1;
        queue<string> q;
        q.push("0000");
        int ans=0;
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                string temp=q.front();
                q.pop();
                if(temp==tar) return ans;
                for(int j=0;j<4;j++)
                {
                    string s1=temp;
                    string s2=temp;
                    s1[j]=(temp[j]=='9'?'0':temp[j]+1);
                    s2[j]=(temp[j]=='0'?'9':temp[j]-1);
                    if(s.find(s1)==s.end())
                    {
                        q.push(s1);
                        s.insert(s1);
                    }
                    if(s.find(s2)==s.end())
                    {
                        q.push(s2);
                        s.insert(s2);
                    }
                    // cout<<s1<<" "<<s2<<endl;
                }
            }
            ans++;
        }
        return -1;
    }
};