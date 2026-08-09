class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int c=0;
        for(int i=0;i<strs[0].size();i++)
        {
            for(int j=0;j+1<strs.size();j++)
            {
                if(strs[j][i]>strs[j+1][i])
                {
                    c++;
                    break;
                }
            }
        }
        return c;
    }
};