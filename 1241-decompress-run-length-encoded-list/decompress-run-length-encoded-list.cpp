class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> output;
        int i=0;
        while(i<nums.size())
        {
            int freq=nums[i];
            int val=nums[i+1];
            while(freq!=0)
            {
                output.push_back(val);
                freq--;
            }
            if(i+1<nums.size())
            {
                i=i+2;
            }
            else
            {
                i++;
            }
        }
        return output;
    }
};