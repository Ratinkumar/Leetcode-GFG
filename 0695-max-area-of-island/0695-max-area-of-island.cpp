class Solution {
public:

    void dfs(vector<vector<int>>& grid,int r,int c,int *max)
    {
        int nr=grid.size();
        int nc=grid[0].size();
        grid[r][c]='0';

        (*max)++;

        if(r-1>=0 && grid[r-1][c]==1) dfs(grid,r-1,c,max);
        if(r+1<nr && grid[r+1][c]==1) dfs(grid,r+1,c,max);
        if(c-1>=0 && grid[r][c-1]==1) dfs(grid,r,c-1,max);
        if(c+1<nc && grid[r][c+1]==1) dfs(grid,r,c+1,max);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int nr=grid.size();
        int nc=grid[0].size();
        if(nr==0) return 0;

        int maxi=0;

        for(int r=0;r<nr;r++)
        {
            for(int c=0;c<nc;c++)
            {
                if(grid[r][c]==1)
                {
                    int max=0;
                    dfs(grid,r,c,&max);
                    maxi=(maxi>max) ? maxi : max;
                }
            }
        }
        return maxi;
    }
};