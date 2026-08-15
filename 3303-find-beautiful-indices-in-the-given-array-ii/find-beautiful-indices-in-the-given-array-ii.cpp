class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        //making lps for a
        vector<int> lps1(a.size(),0);
        int length1=0;
        int i=1;
        while(i<a.size())
        {
            if(a[length1]==a[i])
            {
                lps1[i]=length1+1;
                length1++;
                i++;
            }
            else
            {
                if(length1!=0)
                {
                    length1=lps1[length1-1];
                }
                else
                {
                    lps1[i]=0;
                    i++;
                }
            }
        }
        //making lps2 
        vector<int> lps2(b.size(),0);
        int l2=0;
        int i2=1;
        while(i2<b.size())
        {
            if(b[i2]==b[l2])
            {
                lps2[i2]=l2+1;
                l2++;
                i2++;
            }
            else
            {
                if(l2!=0)
                {
                    l2=lps2[l2-1];

                }
                else
                {
                    lps2[i2]=0;
                    i2++;
                }
            }
        }
        //making kmp for a
        i=0;
        int j=0;
        vector<int> kmp1;
        while(i<s.size())
        {
            if(s[i]==a[j])
            {
                i++;
                j++;
                if(j==a.size())
                {
                    kmp1.push_back(i-j);
                    j=lps1[j-1];
                }

            }
            else
            {
                if(j!=0)
                {
                    j=lps1[j-1];
                }
                else
                {
                    i++;
                }
            }
        }
        i=0;
        j=0;
        vector<int> kmp2;
        while(i<s.size())
        {
            if(s[i]==b[j])
            {
                i++;
                j++;
                if(j==b.size())
                {
                    kmp2.push_back(i-j);
                    j=lps2[j-1];
                }
            }
            else
            {
                if(j!=0)
                {
                    j=lps2[j-1];
                }
                else
                {
                    i++;
                }
            }
        }
        vector<int> ans;
        for(int x:kmp1)
        {
            auto y=lower_bound(kmp2.begin(),kmp2.end(),x-k);
            if(y!=kmp2.end() && *y<=x+k)
            {
                ans.push_back(x);
            }

        }
        return ans;
    }
};