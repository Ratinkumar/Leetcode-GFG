class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>rowStrength;
        for(int i=0;i<mat.size();i++)
        {
            int strength=accumulate(mat[i].begin(),mat[i].end(),0);
            rowStrength.push_back({strength,i});
        }

        sort(rowStrength.begin(),rowStrength.end());

        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(rowStrength[i].second);
        }
        return ans;
    }
};