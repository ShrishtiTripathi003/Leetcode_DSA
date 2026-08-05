class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string ans="";
        int i=0;
        string first=strs[0];
        string last=strs[strs.size()-1];
        while(i<first.size() && i<last.size() && first[i]==last[i])
        {
            ans=ans+first[i];
            i++;
        }
        return ans;
    }
};