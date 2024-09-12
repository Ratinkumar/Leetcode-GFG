class Solution {
public:

    void dfs(int src,unordered_map<int,bool>&vis,unordered_map<int,list<int>>&adj)
    {
        vis[src]=true;

        for(auto it:adj[src])
        {
            if(!vis[it])
            {
                dfs(it,vis,adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count=0;
        unordered_map<int,bool>vis;
        unordered_map<int,list<int>>adj;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj);
                count++;
            }
        }

        return count;
    }
};