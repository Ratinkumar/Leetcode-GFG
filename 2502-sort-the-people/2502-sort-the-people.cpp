class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string>ans;
        vector<pair<int,string>>v;
        for(int i=0;i<names.size();i++)
        {
            v.push_back({heights[i],names[i]});
        }
        sort(v.rbegin(),v.rend());
        for(auto i:v)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};