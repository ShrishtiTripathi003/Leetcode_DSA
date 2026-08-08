class Solution {
public:
    bool halvesAreAlike(string s) {
        int half=s.size()/2;
        string a=s.substr(0,half);
        string b=s.substr(half);
        int i=0;
        int ca=0;
        int cb=0;
        while(i<half)
        {
            if(tolower(a[i])=='a'||tolower(a[i])=='e'||tolower(a[i])=='i'||tolower(a[i])=='o'||tolower(a[i])=='u')
            {
                ca++;
            }
            if(tolower(b[i])=='a'||tolower(b[i])=='e'||tolower(b[i])=='i'||tolower(b[i])=='o'||tolower(b[i])=='u')
            {
                cb++;
            }
            i++;
            
        }
        if(ca==cb)
        {
            return true;
        }
        return false;
    }
};