class Solution {
public:

    void toposort_bfs(int n,vector<int>&toposort,unordered_map<int,list<int>>&adjlist)
    {
        queue<int>q;
        unordered_map<int,int>indegree;

        for(auto i:adjlist)
        {
            for(auto j:i.second)
            {
                indegree[j]++;
            }
        }

        for(int node=0;node<n;node++)
        {
            if(indegree[node]==0)
            {
                q.push(node);
            }
        }

        while(!q.empty())
        {
            int frontnode=q.front();
            q.pop();
            toposort.push_back(frontnode);

            for(auto it:adjlist[frontnode])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adjlist;
        for(vector<int>& i : prerequisites)
        {
            int u=i[0];
            int v=i[1];
            adjlist[v].push_back(u);
        }

        vector<int>toposort;
        toposort_bfs(numCourses,toposort,adjlist);

        if(toposort.size()==numCourses)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};