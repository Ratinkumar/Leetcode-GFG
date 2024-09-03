class Solution {
public:

int lr=0,lc=0;

void dfs(vector<vector<int>> &land, int r, int c)
{
    int nr = land.size();
    int nc = land[0].size();

    land[r][c]=0;

    lr =(lr>r)?lr:r;
    lc = (lc>c)?lc:c;

    if(r-1>=0&&land[r-1][c]==1) dfs(land,r-1,c);
    if(r+1<nr&&land[r+1][c]==1) dfs(land,r+1,c);
    if(c-1>=0&&land[r][c-1]==1) dfs(land,r,c-1);
    if(c+1<nc&&land[r][c+1]==1) dfs(land,r,c+1);

}
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int nr = land.size();
        int nc = land[0].size();
        if(nr==0) return ans;

        for(int r=0;r<nr;r++)
        {
            for(int c=0;c<nc;c++)
            {
                lr=0;
                lc=0;
                if(land[r][c]==1)
                {
                    vector<int> v;
                    v.push_back(r);
                    v.push_back(c);
                    dfs(land,r, c);
                    v.push_back(lr);
                    v.push_back(lc);
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};