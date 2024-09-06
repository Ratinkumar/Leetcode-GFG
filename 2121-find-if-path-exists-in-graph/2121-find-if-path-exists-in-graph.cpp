class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>graph(n,vector<int>());

        for(auto &edge:edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool>visited(n,false);
        visited[source]=true;
        queue<int>q;
        q.push(source);

        while(!q.empty())
        {
            int temp=q.front();
            q.pop();

            if(temp==destination) return true;

            for(int it:graph[temp])
            {
                if(!visited[it])
                {
                    visited[it]=true;
                    q.push(it);
                }
            }
        }
        return false;
    }
};