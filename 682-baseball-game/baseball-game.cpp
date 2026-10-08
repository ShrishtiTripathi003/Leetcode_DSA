class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(string &s:operations)
        {
            if(s=="C")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else if(s=="D")
            {
                int n=st.top();
                n=n*2;
                st.push(n);
            }
            else if(s=="+")
            {
                int first=st.top();
                st.pop();
                int sec=st.top();
                st.push(first);
                int sum=first+sec;
                st.push(sum);
            }
            else
            {
                st.push(stoi(s));
            }
        }
        int sum=0;
        while(!st.empty())
        {
            sum=sum+st.top();
            st.pop();
        }
        return sum;
    }
};