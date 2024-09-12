class Solution {
public:

    void dfs(vector<vector<int>>& image, int i, int j, int oldColor, int color)
    {
        int nr=image.size();
        int nc=image[0].size();
        
        if(i<0 || i>=nr || j<0 || j>=nc || image[i][j] != oldColor)
        {
            return;
        }

        image[i][j] = color;
        dfs(image, i+1, j, oldColor, color);
        dfs(image, i-1, j, oldColor, color);
        dfs(image, i, j-1, oldColor, color);
        dfs(image, i, j+1, oldColor, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int oldColor = image[sr][sc];
        if(oldColor != color)
        {
            dfs(image, sr, sc, oldColor, color);
        }
        return image;
    }
};