class Solution {
public:
    string longestPrefix(string s) {
        //lps
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
                    lps[i]=0;
                    i++;
                }
            }
        }
        return s.substr(0,lps[s.size()-1]);
    }
};