class Solution {
public:
    string reverse(string word)
    {
        string w="";
        int j=word.size()-1;
        while(j>=0)
        {
            w=w+word[j];
            j--;
        }
        return w;
    }
    string reverseWords(string s) {
        string ans="";
        string word="";
        for(int i=0;i<s.size();i++)
        {
            
            if(s[i]==' ')
            {
                ans=ans+reverse(word);
                ans+=" ";
                word="";
            }
            else
            {
                word=word+s[i];
            }
        }
        ans=ans+reverse(word);
        return ans;
    }
};