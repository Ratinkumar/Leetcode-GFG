class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> ans;
        queue<pair<int, vector<int>>>q;
        q.push({0,{0}});
        while(q.size()){
            int t = q.front().first;
            vector<int> v= q.front().second;
            q.pop();
            for(auto at: graph[t]){
                v.push_back(at);
                if(at==graph.size()-1){
                    ans.push_back(v);
                }
                else{
                    q.push({at,v});
                }
                v.pop_back();
            }
        }
        return ans;

    }
};