class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> pus;
        for(int i=0;i+1<nums.size();i++)
        {
           int start=nums[i]+1;
           int end=nums[i+1]-1;
           while(start<=end)
           {
            pus.push_back(start);
            start++;
           }
        }
        return pus;
    }
};