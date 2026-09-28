class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int i=0;
        int j=nums.size()-1;
        int index=nums.size()-1;
        while(i<=j)
        {
            if(abs(nums[i])<abs(nums[j]))
            {
                ans[index]=nums[j]*nums[j];
                j--;
                index--;
            }
            else
            {
                ans[index]=nums[i]*nums[i];
                i++;
                index--;
            }
        }
        return ans;
    }
};