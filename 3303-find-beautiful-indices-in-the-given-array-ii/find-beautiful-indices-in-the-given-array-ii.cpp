class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        //making lps
        vector<int> lps(a.size(),0);
        int length=0;
        int i=1;
        while(i<a.size())
        {
            if(a[length]==a[i])
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
        
        vector<int> lps2(b.size(),0);
        int length1=0;
        int i1=1;
        while(i1<b.size())
        {
            if(b[length1]==b[i1])
            {
                lps2[i1]=length1+1;
                length1++;
                i1++;
            }
            else 
            {
                if(length1!=0)
                {
                    length1=lps2[length1-1];
                    
                }
                else 
                {
                    lps2[i1]=0;
                    i1++;
                }
            }
        }
        //writing kmp
        int j=0;
        int k1=0;
        vector<int> indices;
        while(j<s.size())
        {
            if(s[j]==a[k1])
            {
                j++;
                k1++;             
                if(k1==a.size())
                {
                    indices.push_back(j-k1);
                    k1=lps[k1-1];
                }
            }
            else
            {
                if(k1!=0)
                {
                    k1=lps[k1-1];
                }
                else
                {
                    j++;
                }
            }
        }
        j=0;
        k1=0;
        vector<int> ind;
        while(j<s.size())
        {
            if(s[j]==b[k1])
            {
                j++;
                k1++;
                if(k1==b.size())
                {
                    ind.push_back(j-k1);
                    k1=lps2[k1-1];

                }

            }
            else
            {
                if(k1!=0)
                {
                    k1=lps2[k1-1];
                }
                else
                {
                    j++;
                }
            }
        }
        vector<int> answer;

        int p = 0;

        for (int x : indices) {

            // Move p until b[p] is not too far to the left
            while (p < ind.size() && ind[p] < x - k) {
                p++;
            }

            // If b[p] exists and is within distance k
            if (p < ind.size() && ind[p] <= x + k) {
                answer.push_back(x);
            }
        }

        return answer;
    }
};