class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string f="";
        string g="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='#')
            {
                if(!f.empty())
                {
                    f.pop_back();
                }
            }
            else
            {
                f.push_back(s[i]);
            }
        }
        for(int j=0;j<t.size();j++)
        {
            if(t[j]=='#')
            {
                if(!g.empty())
                {
                    g.pop_back();
                }
            }
            else
            {
                g.push_back(t[j]);
            }
        }
        return f==g;
    }
};