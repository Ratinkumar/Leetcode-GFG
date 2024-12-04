class Solution {
public:

    int UsingRecursion(vector<int>&nums,int index)
    {
        if(index>=nums.size()) return 0;

        int include=nums[index]+UsingRecursion(nums,index+2);
        int exclude=0+UsingRecursion(nums,index+1);

        return max(include,exclude);
    }

    //Using Memoization Method
    int UsingMemo(vector<int>& nums,int index,vector<int>&dp)
    {
        if(index>=nums.size()) return 0;

        if(dp[index]!=-1) return dp[index];

        int include=nums[index]+UsingMemo(nums,index+2,dp);
        int exclude=0+UsingMemo(nums,index+1,dp);

        dp[index]=max(include,exclude);

        return dp[index];
    }

    //Using Tabulation Method
    // int usingTabu(vector<int>&nums,int index,vector<int>&dp)
    // {
    //     if(index>=nums.size()) return 0;


    // }

    int rob(vector<int>& nums) {
        int index=0;
        vector<int>dp(nums.size(),-1);
        int ans=UsingMemo(nums,index,dp);
        return ans;
    }
};