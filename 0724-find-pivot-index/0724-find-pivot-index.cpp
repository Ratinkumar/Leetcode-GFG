class Solution {
public:

    int prefixsumApproach(vector<int>& nums)
    {
        vector<int>lsum(nums.size(), 0);
        vector<int>rsum(nums.size(), 0);

        //calculate left sum
        for(int i=1;i<nums.size();i++)
        lsum[i]=lsum[i-1]+nums[i-1];

        //calculate right sum
        for(int i=nums.size()-2;i>=0;i--)
        rsum[i]=rsum[i+1]+nums[i+1];

        //check 
        for(int i=0;i<nums.size();i++)
        {
            if(lsum[i] == rsum[i])
            return i;
        }
        return -1;
    }

    int pivotIndex(vector<int>& nums) {
        return prefixsumApproach(nums);
    }
};