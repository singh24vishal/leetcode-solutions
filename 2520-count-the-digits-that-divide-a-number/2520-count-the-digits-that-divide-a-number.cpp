class Solution {
public:
    int countDigits(int num) {
        int temp=num;
        int ans=0;
        while(temp)
        {
            int a=temp%10;
            if(num%a==0) ans++;
            temp/=10;
        }
        return ans;
    }
};