class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(n,0) , curr(n, 0);
        for(int j=0; j<m; j++)
        {
            prev[j] = matrix[0][j];
        }

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int d = matrix[i][j]+prev[j];
                int dl = matrix[i][j];
                int dr = matrix[i][j];
                if(j-1>=0)
                {
                    dl+=prev[j-1];
                }
                else
                {
                    dl += 1e9;
                }

                if(j+1<m)
                {
                    dr+=prev[j+1];
                }
                else
                {
                    dr += 1e9;
                }
                curr[j] = min(d,min(dl,dr));

            }
            prev = curr;
        }
        int ans = INT_MAX;
        for(int j=0; j<m; j++)
        {
            ans = min(ans,prev[j]);
        }
        return ans;
    }
};