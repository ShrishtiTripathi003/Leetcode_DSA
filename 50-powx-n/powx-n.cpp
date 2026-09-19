class Solution {
public:
    double power(double x, long long n)
    {
        if(n==0)
        {
            return 1;
        }
        double half=power(x,n/2);
        double result=(half*half);
        if(n%2==1)
        {
            result=result*x;
        }
        return result;

    }
    double myPow(double x, int n) {
        long long N=n;
        if(n<0)
        {
            return 1/power(x,-N);
        }
        return power(x,N);
    }
};