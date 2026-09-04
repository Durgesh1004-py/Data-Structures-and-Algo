class Solution {
public:
    vector<int> leftminindex(vector<int>& heights)
    {
        int n = heights.size();
        stack<int> st;
        vector<int> numsmin(n);

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            numsmin[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return numsmin;

    }

    vector<int> rightminindex(vector<int>& heights)
    {
        int n = heights.size();
        stack<int> st;
        vector<int> numsmin(n);

        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            numsmin[i] = st.empty() ? n : st.top();
            st.push(i);
        } 

        return numsmin;       
    }
    int maxhistogram(vector<int> &heights) {

        int n = heights.size();

        vector<int> leftmin = leftminindex(heights);
        vector<int> rightmin = rightminindex(heights);

        int ans = 0;

        for(int i=0; i<n; i++)
        {
            ans = max(ans, heights[i]*(rightmin[i]-leftmin[i]-1));

        }
        return ans;
        
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> psum(rows, vector<int>(cols, 0));

        for(int j = 0; j < cols; j++)   
        {
            int sum = 0;
        
            for(int i = 0; i < rows; i++)
            {
                if(matrix[i][j] == '0')
                    sum = 0;
                else
                    sum++;
        
                psum[i][j] = sum;
            }
        }

        int maxarea = 0;
        for(int i=0; i<rows; i++)
        {
            maxarea = max(maxarea, maxhistogram(psum[i]));
        }

        return maxarea;

        
    }
};