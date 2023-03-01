class Solution {
public:
    int ladderLength(string st, string en, vector<string>& v) {
        map<string,int> mp2;
        for(auto e:v)
        {
            mp2[e]=1;
        }
        if(!mp2[en]) return 0;
        int ans=INT_MAX;
        queue<pair<string,int>> q;
        q.push({st,1});
        map<string,int> mp;
        mp[st]=1;
        while(!q.empty())
        {
            auto [s,sz]=q.front();
            q.pop();
            if(s==en) 
            {
                return sz;
            }
            for(int i=0;i<s.size();i++)
            {
                for(char c='a';c<='z';c++)
                {
                    string temp=s;
                    temp[i]=c;
                    if(mp2[temp] and !mp[temp])
                    {
                        q.push({temp,sz+1});
                        mp[temp]=1;
                    }
                }
            }
        }
        return 0;
    }
};