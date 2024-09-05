class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int nr=grid.size();
        int nc=grid[0].size();

        int fresh=0;
        queue<pair<int,int>>rotten;

        for(int i=0;i<nr;i++)
        {
            for(int j=0;j<nc;j++)
            {
                if(grid[i][j]==2)
                {
                    rotten.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }

        int time=0;
        vector<int>direction={-1,0,1,0,-1};

        while(!rotten.empty() && fresh>0)
        {
            time++;

            for(int i=rotten.size();i>0;i--)
            {
                auto pos=rotten.front();
                rotten.pop();

                for(int j=0;j<4;j++)
                {
                    int nrow=pos.first+direction[j];
                    int ncol=pos.second+direction[j+1];

                    if(nrow >=0 && nrow<nr && ncol>=0 && ncol<nc && grid[nrow][ncol]==1)
                    {
                        fresh--;
                        grid[nrow][ncol]=2;
                        rotten.push({nrow,ncol});
                    }
                }
            }
        }

        if(fresh>0)
        {
            return -1;
        }
        else
        {
            return time;
        }
        
    }
};