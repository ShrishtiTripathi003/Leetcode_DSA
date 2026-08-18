class Solution {
public:
    int titleToNumber(string col) {
        int result=0;
        for(char c:col)
        {
            result=result*26+(c-'A'+1);
        }
        return result;
    }
};