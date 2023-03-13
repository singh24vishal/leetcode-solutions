class Solution {
public:
    string largestOddNumber(string num) {
        int f=-1,n=num.size();
        for(int i=0;i<n;i++)
        {
            if((num[i]-'0')%2) f=i;
        }
        if(f==-1) return "";
        string ans="";
        for(int i=0;i<=f;i++) ans+=num[i];
        return ans;
    }
};