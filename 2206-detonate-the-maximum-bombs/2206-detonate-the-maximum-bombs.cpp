class Solution {
public:

    bool checkRange(int i,int j,vector<vector<int>>&bombs)
    {
        //a bomb cannot detonante itself
        if(i==j) return false;

        long long xDis=bombs[i][0] - bombs[j][0];
        long long yDis=bombs[i][1] - bombs[j][1];
        long long radius=bombs[i][2];

        return radius*radius >= xDis*xDis + yDis*yDis;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int bomb=bombs.size();

        vector<vector<bool>>graph(bomb,vector<bool>(bomb));

        for(int i=0;i<bomb;i++)
        {
            for(int j=0;j<bomb;j++)
            {
                graph[i][j]=checkRange(i,j,bombs);
            }
        }

        int maxi=0;
        for(int i=0;i<bomb;i++)
        {
            queue<int>q;
            q.push(i);

            vector<int>vis(bomb);
            vis[i]=true;

            int count=0;

            while(!q.empty())
            {
                int curr=q.front();
                q.pop();

                count++;

                for(int j=0;j<bomb;j++)
                {
                    if(graph[curr][j] && !vis[j])
                    {
                        vis[j]=true;
                        q.push(j);
                    }
                }
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};