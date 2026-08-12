class Solution {
public:
    int strStr(string haystack, string needle) {
        //lps
        int length=0;
        int i=1;
        vector<int> lps(needle.size(),0);
        while(i<needle.size())
        {
            if(needle[i]==needle[length])
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
        int j=0;
        int k=0;
        while(k<haystack.size())
        {
            if(haystack[k]==needle[j])
            {
                k++;
                j++;
                if(j==needle.size())
                {
                    return k-j;
                }

            }
            else
            {
                if(haystack[k]!=needle[j])
                {
                    if(j!=0)
                    {
                        j=lps[j-1];
                    }
                    else
                    {
                        k++;
                    }
                }
            }
        }
        return -1;
    }
};