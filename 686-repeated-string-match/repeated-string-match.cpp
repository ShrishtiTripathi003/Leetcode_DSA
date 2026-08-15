class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        // making lps
        int length=0;
        vector<int> lps(b.size(),0);
        int i=1;
        while(i<b.size())
        {
            if(b[i]==b[length])
            {
                lps[i]=length+1;
                length++;
                i++;
            }
            else
            {
                if(length!=0)
                {
                    length=lps[length-1];
                }
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
        // making kmp
        i=0;
        int j=0;
        int max_len=2*(a.size())+b.size();
        while(i<max_len)
        {
            if(a[i%a.size()]==b[j])
            {
                i++;
                j++;
                if(j==b.size())
                {
                    return (i+a.size()-1)/a.size();
                }
            }
            else
            {
                if(j!=0)
                {
                    j=lps[j-1];
                }
                else
                {
                    i++;
                }
            }
        }
        return -1;
    }
};