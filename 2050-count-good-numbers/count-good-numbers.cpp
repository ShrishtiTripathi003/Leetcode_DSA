class Solution {
public:
    long long mod=1000000007;
    long long power(long long a,long long b)
    {
        if(b==0)
        {
            return 1;
        }
        long long half=power(a,b/2);
        long long result=(half*half)%mod;
        if(b%2==1)
        {
            result=(result*a)%mod;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        return (power(5,(n+1)/2)*power(4,n/2))%mod;
    }
};