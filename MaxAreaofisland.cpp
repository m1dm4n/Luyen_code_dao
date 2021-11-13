//Ở đây người ta chỉ yêu cầu viết hàm thôi :))
class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(nullptr);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;
        int d1[4] = {0, 1, 0, -1}, d2[4] = {1, 0, -1, 0}, an{0};
        for(int i = 0; i<grid.size(); ++i) 
        {
            vector<int>::iterator it = find(grid[i].begin(), grid[i].end(), 1);
                while(it != grid[i].end()) {
                    q.push({i, (it-grid[i].begin())}) ;
                    grid[i][it-grid[i].begin()]=0;
                    int tmp{0};
                    while (!q.empty()) 
                    {
                        for (int k = 0; k < 4; ++k)
                        {
                            int m = q.front().first+d1[k], n = q.front().second+d2[k];
                            if (m>=0 && m<grid.size() && n>=0 && n<grid[0].size() && grid[m][n]==1) 
                            {
                                grid[m][n]=0;
                                q.push({m, n});
                            }
                        }
                        q.pop();
                        ++tmp;
                    }
                    an = (an>tmp) ? an : tmp;
                }
        }
        return an;
    }
};
