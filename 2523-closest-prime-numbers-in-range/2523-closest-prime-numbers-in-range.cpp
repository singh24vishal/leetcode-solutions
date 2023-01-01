class Solution {
public:
    vector<bool> prime;
    int N=1e6+3;
    vector<int> v;
    void seive(){
    prime.resize(N,true);
 prime[0]=prime[1]=false;
 for(int i=2;i*i<=N;i++){
   if(prime[i]==true){
     for(int j=i*i;j<N;j+=i) prime[j]=false;
   }
 }
}
    void fun()
    {
        for(int i=2;i<N;i++)
        {
            if(prime[i]) v.push_back(i);
        }
    }
    
    vector<int> closestPrimes(int left, int right) {
        seive();
        fun();
        vector<int> ans={-1,-1};
        int dif=INT_MAX;
        int a=lower_bound(v.begin(),v.end(),left)-v.begin();
        int b=upper_bound(v.begin(),v.end(),right)-v.begin()-1;
        // cout<<v[a]<<" "<<v[b];
        for(int i=a+1;i<=b;i++)
        {
            int temp=v[i]-v[i-1];
            if(temp<dif) {ans={v[i-1],v[i]}; dif=temp;}
        }
        return ans;
    }
};