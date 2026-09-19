class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        int k=0;
        bool sign=false;
        while(k<s.size() && s[k]==' ')
        {
            k++;
        }
        if(k<s.size() && s[k]=='-')
        {
            sign=true;
            k++;
        }
        else if(k<s.size() && s[k]=='+')
        {
            k++;
        }

        while(k<s.size() && isdigit(s[k]))
        {
            int digit=s[k]-'0';
            ans=ans*10+digit;
            if(!sign && ans>INT_MAX)
            {
                return INT_MAX;
            }
            if(sign && -ans<INT_MIN)
            {
                return INT_MIN;
            }
            k++;
        }
        if(sign)
        {
            ans=-ans;
        }
        return ans;
    }
};