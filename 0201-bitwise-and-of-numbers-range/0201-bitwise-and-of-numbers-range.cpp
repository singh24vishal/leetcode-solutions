class Solution {
public:
    int rangeBitwiseAnd(int a, int b) {
        int s=0;
        while(a!=b)
        {
            a/=2;
            b/=2;
            s++;
        }
        return (a<<s);
    }
};