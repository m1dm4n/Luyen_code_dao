class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(nullptr);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int r, int c, int newColor) {
        queue<pair<int, int>> q;
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, n = image[r][c];
        image[r][c]=-1;
        q.push({r, c});
        while (!q.empty())
        {
            for (int k = 0; k < 4; ++k)
            {
                int x = q.front().first + dx[k];
                int y = q.front().second + dy[k];
                if (x >= 0 && x < image.size() && y >= 0 && y < image[0].size() && image[x][y] == n)
                {
                    image[x][y] = -1;
                    q.push({x, y});
                }
            }
            q.pop();
        }
        for(int i=0; i<image.size(); ++i)
            replace (image[i].begin(), image[i].end(), -1, newColor);
        return image;
    }
};
