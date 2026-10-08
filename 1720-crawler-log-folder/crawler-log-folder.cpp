class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        for(string l:logs)
        {
            if(l=="../")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else if(l!="./")
            {
                st.push(l);
            }
        }
        return st.size();
    }
};