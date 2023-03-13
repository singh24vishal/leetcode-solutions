class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            string temp="";
            for(int j=i;j<n;j++) temp+=s[j];
            for(int j=0;j<i;j++) temp+=s[j];
            if(temp==goal) return true;
        }
        return false;
    }
};