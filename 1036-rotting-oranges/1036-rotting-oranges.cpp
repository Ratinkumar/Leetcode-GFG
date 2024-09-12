class Solution {
public:

    void dfs(vector<vector<int>>& grid,int i,int j,int min)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0 || (grid[i][j]<min && grid[i][j]>1))
        {
            return;
        }

        grid[i][j]=min;
        dfs(grid,i+1,j,min+1);
        dfs(grid,i-1,j,min+1);
        dfs(grid,i,j+1,min+1);
        dfs(grid,i,j-1,min+1);

    }

    int orangesRotting(vector<vector<int>>& grid) {
        int min=2;//minute

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    //dfs
                    dfs(grid,i,j,min);
                }
            }
        }

        for(auto v:grid)//it gives me a vector
        {
            for(auto it:v)//and now iterate on that vector
            {
                if(it==1) return -1;
                min=max(min,it);
            }
        }

        return min - 2;
    }
};