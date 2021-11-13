class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> an(mat.size(), vector<int>(mat[0].size(), -1));
        queue<pair<int, int>> q;
        int o[4] = {0, 1, 0, -1},p[4] = {-1,0, 1 ,0};
        for (int  i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat[0].size(); ++j)
            {
                if(mat[i][j] == 0)
                {
                    an[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while (!q.empty()) {
            int m = q.front().first, n = q.front().second;
            for (int d=0; d<4; ++d){
                if(m+o[d]>=0 && m+o[d]<mat.size() && n+p[d]>=0 && n+p[d]<mat[0].size() && an[m+o[d]][n+p[d]] ==-1) {
                    q.push({m+o[d], n+p[d]});
                    an[m+o[d]][n+p[d]] = an[m][n] + 1;
                }
            }
            q.pop();
        }
        return an;
    }
};
