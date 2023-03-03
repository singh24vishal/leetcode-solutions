class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        int n=s.size(), lim=pow(2,s.size());  
        unordered_map<string,int> mp;
        for(int i=0;i<lim;i++)
        {
            int j=0,temp=i;
            string str3=s;
            while(temp)
            {
                if(temp&1)
                {
                    if(str3[j]>='A' and str3[j]<='Z') str3[j]= 'a'+(str3[j]-'A');
                    else if(str3[j]>='a' and str3[j]<='z') str3[j]= 'A'+(str3[j]-'a');
                }
                temp/=2;
                j++;
            }
            if(!mp[str3])
            {
                mp[str3]=1;
                ans.push_back(str3);
            }
        }
        return ans;
    }
};