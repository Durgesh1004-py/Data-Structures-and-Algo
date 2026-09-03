class Solution {
public:
    vector<int> findNse(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> Nse(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            Nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return Nse;
    }

    vector<int> findPse(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> Pse(n);
        stack<int> st;

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                st.pop();
            }
            Pse[i] = st.empty() ? -1 : st.top();
            st.push(i) ;
        }

        return Pse;

    }
    int sumSubarrayMins(vector<int>& arr) {
        int total = 0;
        int n = arr.size();

        vector<int> nse =findNse(arr);
        vector<int> pse =findPse(arr);

        int mod  = 1000000007;

        for(int i=0; i<n; i++)
        {
            int left = i-pse[i];
            int right = nse[i]-i;

            total = (total +(right*left*1LL*arr[i])%mod)%mod;
        }

        return total;

        
    }
};