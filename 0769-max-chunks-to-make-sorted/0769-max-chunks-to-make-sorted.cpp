class Solution {
public:
    int fun(vector<int>&v,int i,int n)
    {
        for(int j=i+1;j<n;j++)
        {
            vector<int> temp=v;
            sort(temp.begin()+i,temp.begin()+j+1);
            // for(auto e:temp) cout<<e<<" "; cout<<endl;
            int f=0;
            for(int k=i;k<=j;k++)
            {
                if(temp[k]!=k) f=1;
            }
            if(f==0)
            {
                v=temp;
                return j;
            }
        }
        return n;
    }
    int maxChunksToSorted(vector<int>& v) {
        int ans=0,n=v.size();
        for(int i=0;i<n;i++)
        {
            if(v[i]==i) ans++;
            else 
            {
                int j=fun(v,i,n);
                // cout<<i<<" "<<j<<endl;
                i=j;
                ans++;
            }
        }
        return ans;
    }
};