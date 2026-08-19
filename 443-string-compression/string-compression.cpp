class Solution {
public:
    int compress(vector<char>& chars) {
        int index=0;
        for(int i=0;i<chars.size();i++)
        {
            char c=chars[i];
            int count=0;
            while(i<chars.size() && chars[i]==c)
            {
                i++;
                count++;
            }
            if(count==1)
            {
                chars[index++]=c;
            }
            else
            {
                chars[index++]=c;
                string str=to_string(count);
                for(char c:str)
                {
                    chars[index++]=c;
                }
            }
            i--;
        }
        chars.resize(index);
        return index;
    }
};