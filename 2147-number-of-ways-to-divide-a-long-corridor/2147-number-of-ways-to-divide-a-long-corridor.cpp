class Solution {
public:
    int numberOfWays(string s) {
        int n=s.size();
        int mod=1e9+7;
        int ans=1,c=0,i=0,j=n-1;
        while(i<n and s[i]=='P') i++;
        while(j>=0 and s[j]=='P') j--;
        if(j<=i) return 0;
        for(int k=i;k<=j;k++)
        {
            if(s[k]=='S') c++;
            if(c==2)
            {
                c=0;
                int ctr=1,idx=k+1;
                while(idx<=j and s[idx]=='P') 
                {
                    idx++;
                    ctr++;
                }
                k=idx-1;
                long long temp=1ll*ans*ctr;
                ans=temp%mod;
            }
        }
        if(c==1) return 0;
        return ans;
    }
};