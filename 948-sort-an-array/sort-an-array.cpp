class Solution {
public:
    void merge(vector<int>& nums,int l,int m,int r)
    {
        int n1=m-l+1;
        int n2=r-m;
        vector<int> L1(n1);
        vector<int> L2(n2);
        int k=l;
        for(int i=0;i<n1;i++)
        {
            L1[i]=nums[k];
            k++;
        }
        for(int i=0;i<n2;i++)
        {
            L2[i]=nums[k];
            k++;
        }
        k=l;
        int i=0;
        int j=0;
        while(i<n1 && j<n2)
        {
            if(L1[i]<L2[j])
            {
                nums[k]=L1[i];
                i++;
            }
            else
            {
                nums[k]=L2[j];
                j++;
            }
            k++;
        }
        while(i<n1)
        {
            nums[k]=L1[i];
            i++;
            k++;
        }
        while(j<n2)
        {
            nums[k]=L2[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<int>& nums,int l,int r)
    {
        if(l>=r)
        {
            return;
        }
        int mid=(l+r)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        merge(nums,l,mid,r);
    }
    vector<int> sortArray(vector<int>& nums)
    {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};