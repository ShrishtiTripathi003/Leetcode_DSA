class Solution {
public:
    void solve(vector<char>& s,int i,int n)
    {
        if(i>=n)
        {
            return;
        }
    
        swap(s[i],s[n]);
        solve(s,i+1,n-1);
    }
    void reverseString(vector<char>& s) {
        int i=0;
        //base case
        if(s.empty())
        {
            return;
        }
        int n=s.size()-1;
        solve(s,i,n);
    }
};