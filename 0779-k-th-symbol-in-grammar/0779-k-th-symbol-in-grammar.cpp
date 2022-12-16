class Solution {
public:
    int fun(int n,int k)
    {
        if(n==1) return 0;
        int t=pow(2,n-1);
        if(k>t/2)
            return !fun(n-1,k-t/2);
        return fun(n-1,k);
    }
    int kthGrammar(int n, int k) {
        return fun(n,k);
    }
};