class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        int ans=0;
        map<int,int>::iterator itr;
        for(itr=m.begin();itr!=m.end();itr++)
        {
            int k=itr->second;
            ans=(ans+((k*(k-1))/2));
        }
        return ans;
    }
};