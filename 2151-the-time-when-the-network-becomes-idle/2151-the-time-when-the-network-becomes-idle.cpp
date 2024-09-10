class Solution {
public:
    //dijkastra algo
    int disj(vector<vector<pair<int,int>>>&adj,vector<int>& patience)
    {
        int n=patience.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(n,INT_MAX);
        vis[0]=0;
        pq.push({0,0});
        while(!pq.empty())
        {
            int currtime=pq.top().first;
            int currnode=pq.top().second;
            pq.pop();

            for(auto &ad:adj[currnode])
            {
                int nextnode=ad.first;
                int nexttime=ad.second;
                if(currtime+nexttime<vis[nextnode])
                {
                    vis[nextnode]=currtime+nexttime;
                    pq.push({vis[nextnode],nextnode});
                }
            }
        }
        int ans=0;
        for(int i=1;i<n;i++)
        {
            int time=2*vis[i],cur;
            if(patience[i]>=time)
            {
                cur=time;
            }
            else
            {
                cur=((time-1)/patience[i]) * patience[i];
                cur+=time;
            }
            ans=max(ans,cur+1);
        }
        return ans;
    }

    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n=patience.size();
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it:edges)
        {
            adj[it[0]].push_back({it[1],1});
            adj[it[1]].push_back({it[0],1});
        }

        return disj(adj,patience);
    }
};