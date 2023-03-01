class Solution {
public:
    int ladderLength(string st, string en, vector<string>& v) {
        unordered_map<string,int> mp2;
        for(auto e:v) mp2[e]=1;
        if(!mp2[en]) return 0;
        queue<pair<string,int>> q;
        q.push({st,1});
        unordered_map<string,int> mp;
        mp[st]=1;
        while(!q.empty())
        {
            auto [s,sz]=q.front();
            q.pop();
            if(s==en) return sz;
            for(int i=0;i<s.size();i++)
            {
                char rep=s[i];
                for(char c='a';c<='z';c++)
                {
                    s[i]=c;
                    if(mp2[s] and !mp[s])
                    {
                        q.push({s,sz+1});
                        mp[s]=1;
                    }
                }
                s[i]=rep;
            }
        }
        return 0;
    }
};