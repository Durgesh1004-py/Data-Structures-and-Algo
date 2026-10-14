class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        st.push(n-1);
        vector<int> ans(n);
        ans[n-1] = 0;

        for(int i=n-2; i>=0; i--)
        {
            while(!st.empty() && temperatures[st.top()]<=temperatures[i])
            {
                st.pop();
            }  
            if(st.empty())
            {
                ans[i] = 0;
                st.push(i);
            }
            else
            {
                int j = st.top();
                ans[i] = j-i;
                st.push(i);
            }
        }
        return ans;
        
    }
};