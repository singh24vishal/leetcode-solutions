class Solution {
public:
    vector<int> get(vector<int>&v,int n,int k)
    {
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            while(ans.size()>0 and ans.back()<v[i] and ans.size()+n-i>k) ans.pop_back();
            if(ans.size()<k) ans.push_back(v[i]);
        }
        return ans;
    }
    bool fun(vector<int>&v1,int i,vector<int>&v2,int j)
    {
        while(i<v1.size() and j<v2.size() and v1[i]==v2[j]) 
        {
            i++;
            j++;
        }
        return j==v2.size() or (i<v1.size() and v1[i]>v2[j]);
    }
    vector<int> merge(vector<int>&v1,vector<int>&v2,int k)
    {
        vector<int> ans(k);
        for(int i=0,j=0,t=0;t<k;t++)
        {
            if(fun(v1,i,v2,j)) 
            ans[t]=v1[i++];
            else ans[t]=v2[j++];
        }
        return ans;
    }
    
    vector<int> maxNumber(vector<int>& v1, vector<int>& v2, int k) {
        int n=v1.size(), m=v2.size();
        vector<int> ans(k);
        for(int i=0;i<=k;i++)
        {
           if(i<=n and k-i<=m)
           {
                vector<int> a=get(v1,n,i);
                vector<int> b=get(v2,m,k-i);
                vector<int> c=merge(a,b,k);
                ans=max(ans,c);
           }
        }
        return ans;
    }
    
};