class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+")
            {
                int sec=st.top();
                st.pop();
                int first=st.top();
                st.pop();
                st.push(sec+first);
            }
            else if(tokens[i]=="-")
            {
                int sec=st.top();
                st.pop();
                int first=st.top();
                st.pop();
                st.push(first-sec);
            }
            else if(tokens[i]=="*")
            {
                int sec=st.top();
                st.pop();
                int first=st.top();
                st.pop();
                st.push(first*sec);
            }
            else if(tokens[i]=="/")
            {
                int sec=st.top();
                st.pop();
                int first=st.top();
                st.pop();
                st.push(first/sec);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};