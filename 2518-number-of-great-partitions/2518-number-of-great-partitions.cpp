#define ll long long
class Solution {
public:
    int mod=1e9+7;
    ll add(ll x,ll y){ll res=x+y ; return(res>=mod?res-mod:res);}
ll mul(ll x,ll y){ll res=(x%mod)*(y%mod) ; return(res>=mod?res%mod:res);}
ll sub(ll x,ll y){ll res=x-y ; return(res<0?res+mod:res);}
ll power(ll x, ll y) {if (y < 0) return 1; ll res = 1; x %= mod; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll inv(ll x){return power(x,mod-2);}
    int countPartitions(vector<int>& v, int k) {
        ll n=v.size();
        ll totsum=accumulate(v.begin(),v.end(),0ll);
        if(totsum<2*k) return 0;
        vector<vector<ll>> dp(n+1,vector<ll>(k,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(v[i-1]>j) dp[i][j]=dp[i-1][j];
                else dp[i][j]=add(dp[i-1][j],dp[i-1][j-v[i-1]]);
            }
        }
        ll sum=0;
        for(int i=1;i<k;i++) sum=add(sum,dp[n][i]);
        sum=mul(2,sum);
        ll tot=sub(power(2,n),2);
        ll ans=sub(tot,sum);
        return ans;
    }
};