class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int idx=max_element(nums.begin(),nums.end())-nums.begin();
        int mx=nums[idx];
        for(int i=0;i<nums.size();i++)
        {
            if(i!=idx && mx<2*nums[i])
            {
                return -1;
            }
        }
        return idx;
    }
};