class Solution {
public:

    int usingMemo(int n,vector<int>&dp)
    {
        if(n==0 || n==1)
        {
            return n;
        }

        if(dp[n]!=-1)
        {
            return dp[n];
        }

        dp[n]=usingMemo(n-1,dp)+usingMemo(n-2,dp);
        return dp[n];
    }

    int fib(int n) {
        vector<int>dp(n+1,-1);
        int ans=usingMemo(n,dp);
        return ans;
    }
};