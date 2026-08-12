class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // wrinting code of lps
        int length=0;
        int i=1;
        vector<int> lps(s.size(),0);
        while(i<s.size())
        {
            if(s[i]==s[length])
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
                    lps[length]=0;
                    i++;
                }
            }
        }
        int longestprefix=lps[s.size()-1];
        int size=s.size()-longestprefix;
        return longestprefix>0 && s.size()%size==0;
    }
};