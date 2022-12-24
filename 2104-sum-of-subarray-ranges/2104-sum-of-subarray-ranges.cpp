#define ll long long
class Solution {
public:
    long long subArrayRanges(vector<int>& v) {
        stack<ll> st,st2;
        ll n=v.size();
        vector<ll> a(n,-1),b(n,n),c(n,-1),d(n,n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and v[st.top()]>=v[i]) st.pop();
            if(!st.empty()) a[i]=st.top();
            st.push(i);
            while(!st2.empty() and v[st2.top()]<=v[i]) st2.pop();
            if(!st2.empty()) c[i]=st2.top();
            st2.push(i);
        }
        while(!st.empty()) st.pop();
        while(!st2.empty()) st2.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and v[st.top()]>v[i]) st.pop();
            if(!st.empty()) b[i]=st.top();
            st.push(i);
            while(!st2.empty() and v[st2.top()]<v[i]) st2.pop();
            if(!st2.empty()) d[i]=st2.top();
            st2.push(i);
        }
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ll p=i-a[i];
            ll q=b[i]-i;
            ll r=i-c[i];
            ll s=d[i]-i;
            ans+=(r*s-p*q)*v[i];
        }
        // for(auto e:a) cout<<e<<" "; cout<<endl;
        // for(auto e:b) cout<<e<<" "; cout<<endl;
        // for(auto e:c) cout<<e<<" "; cout<<endl;
        // for(auto e:d) cout<<e<<" "; cout<<endl;
        return ans;
    }
};