class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n=nums.size();

        vector<int>ans;
        map<int,int>mp;

        for(int i=0;i<n;i++)
        {
            int m=nums[i].size();
            for(int j=0;j<m;j++)
            {
                mp[nums[i][j]]++;
            }
        }

        for(auto &it : mp)
        {
            if(it.second==n)
            {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};