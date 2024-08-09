class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int s=0;
        int e=0;
        int sum=0;
        int prefixZero=0;
        int count=0;

        while(e < nums.size())
        {
            sum=sum+nums[e];

            while(s<e && (sum > goal || nums[s]==0))
            {
                if(nums[s]==1)
                {
                    prefixZero=0;
                }
                else
                {
                    prefixZero+=1;
                }

                sum=sum-nums[s];

                s++;
            }
            if(sum==goal)
            {
                count+=prefixZero+1;
            }
            e++;
        }
        return count;
    }
};