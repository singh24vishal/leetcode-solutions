class Solution {
public:
    int maxDepth(string s) {
        int c=0,ans=-1;
        for(auto e:s)
        {
            if(e=='(') c++;
            else if(e==')') c--;
            ans=max(ans,c);
        }
        return ans;
    }
};