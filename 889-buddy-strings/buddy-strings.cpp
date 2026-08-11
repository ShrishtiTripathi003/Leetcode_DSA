class Solution {
public:
    bool checkFreq(string &s)
    {
        unordered_set<int> st;
        for(char c:s)
        {
            st.insert(c);
        }
        if(st.size()!=s.size())
        {
            return true;
        }
        return false;
    }
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())
        {
            return false;
        }
        if(s==goal)
        {
            return checkFreq(s);
        }
        vector<int> index;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=goal[i])
            {
                index.push_back(i);
            }
        }
        if(index.size()!=2)
        {
            return false;
        }
        swap(s[index[0]],s[index[1]]);
        return s==goal;

    }
};