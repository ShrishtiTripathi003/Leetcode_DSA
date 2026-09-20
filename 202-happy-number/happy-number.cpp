class Solution {
public:
    int getN(int n)
    {
        int sq=0;
        while(n!=0)
        {
            int dig=n%10;
            sq=sq+dig*dig;
            n=n/10;
        }
        return sq;
    }
    bool isHappy(int n) {
        int slow=getN(n);
        int fast=getN(getN(n));
        while(slow!=fast)
        {
            slow=getN(slow);
            fast=getN(getN(fast));
        }
        return slow==1;
    }
};