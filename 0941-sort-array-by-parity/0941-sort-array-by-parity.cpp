class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;

        while(start < end)
        {
            if(start < end && nums[start] % 2 ==0)
            start++;

            if(start < end && nums[end] % 2==1)
            end--;

            swap(nums[start],nums[end]);
        }
        return nums;
    }
};