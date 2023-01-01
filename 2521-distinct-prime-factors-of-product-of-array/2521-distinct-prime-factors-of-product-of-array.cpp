class Solution {
public:
    vector<int> v;
    int N=1e3+4;
    vector<bool> prime;
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
    int distinctPrimeFactors(vector<int>& nums) {
        seive();
        fun();
        set<int> st;
        for(auto e:nums)
        {
            for(auto i:v)
            {
                if(e%i==0)
                {
                    st.insert(i);
                    e/=i;
                }
            }
        }
        return st.size();
    }
};