class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="",temp="";
        int x=0;
        for(auto e:s)
        {
            temp+=e;
            if(e=='(') x++;
            else x--;
            if(x==0)
            {
                for(int i=1;i<temp.size()-1;i++) ans+=temp[i];
                temp="";
            }
        }
        return ans;
    }
};