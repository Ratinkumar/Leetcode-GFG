class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int even=0;
        int odd=1;
        vector<int>ans(nums.size(),-1);
        for(int i=0;i<nums.size();i++)
        {
            int num=nums[i];
            if(num > 0)
            {
                ans[even]=num;
                even += 2;
            }
            else
            {
                ans[odd]=num;
                odd += 2;
            }
        }
        return ans;
    }
};