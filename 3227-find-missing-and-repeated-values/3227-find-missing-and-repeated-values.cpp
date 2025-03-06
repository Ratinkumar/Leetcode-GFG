class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int>mp;
        int n=grid.size();

        for(auto i:grid)
        {
            for(int j:i)
            {
                mp[j]++;
            }
        }

        int missing_num,repeated_num;

        for(int i=1;i<=n*n;i++)
        {
            if(!mp.count(i))
            {
                missing_num=i;
            }
            else if(mp[i]==2)
            {
                repeated_num=i;
            }

        }

        return {repeated_num,missing_num};
    }
};