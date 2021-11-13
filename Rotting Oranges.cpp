class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int orangesRotting(vector<vector<int>>& matrix) 
    {
        queue <int> x,y;  
        int num{0}, dem{0}, tmp1{0};
        int o[4] = {0, 1, 0, -1};
        int p[4] = {-1,0, 1 ,0};
        for (int  i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if(matrix[i][j] == 1) {++tmp1;}
                if(matrix[i][j] == 2)
                {
                    x.push(i);
                    y.push(j);
                }
            }
        }
        if(tmp1==0 ) return 0;
        while (!x.empty()) 
        {
            num=0;
            int n=x.size();
            for (int a = 0; a < n; ++a) 
            {
                for (int d = 0; d < 4; ++d)
                {
                    int m = x.front()+o[d], n = y.front()+p[d];
                    if( m >= 0 && m < matrix.size() &&  n >= 0 && n < matrix[0].size() && matrix[m][n]==1)
                    {
                        matrix[m][n] = 3;
                        x.push(m);
                        y.push(n);
                        ++num;
                        --tmp1;
                    }
                }
                x.pop();
                y.pop();
            }
            if (num!=0) ++dem;
        }
        return tmp1 == 0 ? dem : -1;
    }
};
