class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int>ans;
        int n=mat.size();
        int onescount=INT_MIN;
        int rowno=-1;

        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==1)
                {
                    count++;
                }
            }
            if(count > onescount)
            {
                onescount=count;
                rowno=i;
            }
        }
        ans.push_back(rowno);
        ans.push_back(onescount);

        return ans;
    }
};