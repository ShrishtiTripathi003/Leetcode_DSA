class Solution {
public:
    string convertToTitle(int column) {
        string result="";
        while(column>0)
        {
            column--;
            result=char(column%26+'A')+result;
            column=column/26;
        }
        return result;
    }
};