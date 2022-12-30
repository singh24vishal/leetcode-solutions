class Solution {
public:
    vector<int> topStudents(vector<string>& pf, vector<string>& nf, vector<string>& report, vector<int>& sid, int k) {
        map<string,int>mp1,mp2;
        map<int,int> mp3;
        for(auto e:pf) mp1[e]=1;
        for(auto e:nf) mp2[e]=1;
        int n=sid.size();
        vector<int> ans;
        set<int> st;
        for(auto e:sid) st.insert(e);
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            stringstream s(report[i]);
            string str;
            while(s>>str)
            {
                if(mp1[str]) mp3[sid[i]]+=3;
                if(mp2[str]) mp3[sid[i]]-=1;
            }
        }
        for(auto e:mp3) v.push_back({e.second,e.first});
        sort(v.begin(),v.end(),[&](pair<int,int> a, pair<int,int> b)
             {
                 if(a.first!=b.first) return a.first>b.first;
                 return a.second<b.second;
             });
        int sz=min(k,(int)v.size());
        for(int i=0;i<sz;i++) {ans.push_back(v[i].second); st.erase(v[i].second);}
        while(ans.size()<k)
        {
            ans.push_back(*st.begin());
            st.erase(st.begin());
        }
        return ans;
    }
};