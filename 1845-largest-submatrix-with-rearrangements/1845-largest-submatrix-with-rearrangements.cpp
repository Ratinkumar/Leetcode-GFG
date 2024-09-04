class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int nr=matrix.size();
        int nc=matrix[0].size();

        for(int i=1;i<nr;i++)
        {
            for(int j=0;j<nc;j++)
            {
                if(matrix[i][j]==1)
                {
                    matrix[i][j]=matrix[i-1][j] + 1;
                }
            }
        }

        int area=0;

        for(auto &row:matrix)
        {
            sort(row.rbegin(),row.rend());
            for(int j=0;j<nc;j++)
            {
                area=max(area,(j+1)*row[j]);
            }
        }

        return area;
    }
};