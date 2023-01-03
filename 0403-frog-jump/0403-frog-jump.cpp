class Solution {
public:
    bool fun(int pos,int k,map<int,bool>&mp,map<pair<int,int>,bool>&mp2,int last)
    {
        if(pos>last) return false;
        if(pos==last) return true;
        if(mp[pos]!=true) return false;
        if(mp2.find({pos,k})!=mp2.end()) return mp2[{pos,k}];
        bool a,b,c;
        a=false,b=false,c=false;
        if(k!=1) a=fun(pos+k-1,k-1,mp,mp2,last);
        b=fun(pos+k,k,mp,mp2,last);
        c=fun(pos+k+1,k+1,mp,mp2,last);
        return mp2[{pos,k}]=(a or b or c);
    }
    bool canCross(vector<int>& v) {
       if(v[0]!=0 or v[1]!=1) return false;
        map<int,bool> mp;
        for(auto e:v) mp[e]=true;
        map<pair<int,int>,bool> mp2;
        return fun(1,1,mp,mp2,v.back());
    }
};