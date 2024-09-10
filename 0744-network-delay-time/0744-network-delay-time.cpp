class Solution {
public:

    int disj(vector<vector<pair<int,int>>> &adj, int src, int n) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0, src});
        vector<int> vis(n+1, INT_MAX);
        vis[src] = 0;

        while(!pq.empty()) {
            int currtime = pq.top().first;
            int currnode = pq.top().second;
            pq.pop();

            for(auto &ad : adj[currnode]) {
                int nextnode = ad.first;
                int nexttime = ad.second;
                
                if(vis[nextnode] > currtime + nexttime) {
                    vis[nextnode] = currtime + nexttime;
                    pq.push({vis[nextnode], nextnode});
                }
            }
        }

        int maxTime = *max_element(vis.begin() + 1, vis.end());
        return maxTime == INT_MAX ? -1 : maxTime;
    }

    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        int ne = times.size();
        for(int i = 0; i < ne; i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        int ans = disj(adj, k, n);
        return ans;
    }
};
