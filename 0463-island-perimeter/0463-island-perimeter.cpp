class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int nr=grid.size();
        int nc=grid[0].size();

        int count=0;

        for(int i=0;i<nr;i++)
        {
            for(int j=0;j<nc;j++)
            {
                if(grid[i][j]==1)
                {
                    count+=4;

                    //if the cell below the current one is also a part of island
                    if(i<nr-1 && grid[i+1][j]==1) count-=2;
                    //if the cell right to the current one is also a part of island
                    if(j<nc-1 && grid[i][j+1]==1) count-=2;
                }
            }
        }
        return count;
    }
};