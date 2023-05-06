class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        vector<int> v1,v2;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') v1.push_back(i);
            else if(s[i]=='*') v2.push_back(i);
            else 
            {
                if(v1.size()) v1.pop_back();
                else if(v2.size()) v2.pop_back();
                else return false;
            }
        }
        while(v1.size() and v2.size() and v1.back()<v2.back())
        {
            v1.pop_back();
            v2.pop_back();
        }
        return v1.size()==0;
    }
};