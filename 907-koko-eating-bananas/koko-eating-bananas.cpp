class Solution {
public:
    long long sumD(vector<int>& piles, int mid)
    {
        long long sum = 0;
        for(int i=0;i<piles.size();i++)
        {
            sum+=(1LL*piles[i]+mid-1)/mid;
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(sumD(piles,mid)<=h)
            {
                high=mid-1;
                ans=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};