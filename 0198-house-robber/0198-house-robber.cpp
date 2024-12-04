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
    int UsingTabu(vector<int>&nums,int index,vector<int>&dp)
    {
        int n=nums.size();

        dp[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--)
        {
            int include=nums[i]+dp[i+2];
            int exclude=0+dp[i+1];

            dp[i]=max(include,exclude);
        }

        return dp[index];
    }

    //Using Space Opimization
    int UsingSO(vector<int>&nums)
    {
        int n=nums.size();
        int prev=nums[n-1];
        int next=0;
        int curr=0;

        for(int i=n-2;i>=0;i--)
        {
            // int tempAns=0;
            // if(i+2 < n)
            // {
            //     tempAns=next;
            // }
            int include=nums[i]+next;
            int exclude=0+prev;
            curr=max(include,exclude);

            next=prev;
            prev=curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int index=0;
        int n=nums.size();

        // int ans=UsingRecursion(nums,index);
        // return ans;

        // vector<int>dp(n,-1);
        // int ans=UsingMemo(nums,index,dp);
        // return ans;
        
        // vector<int>dp(n+1,0);
        // int ans=UsingTabu(nums,index,dp);
        // return ans;

        int ans=UsingSO(nums);
        return ans;
    }
};