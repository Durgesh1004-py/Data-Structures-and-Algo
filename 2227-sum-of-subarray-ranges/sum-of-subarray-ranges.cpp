class Solution {
public:
    vector<int> findMiniNse(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> Nsemini(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            Nsemini[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return Nsemini;
    }

    vector<int> findMiniPse(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> Psemini(n);
        stack<int> st;

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                st.pop();
            }
            Psemini[i] = st.empty() ? -1 : st.top();
            st.push(i) ;
        }

        return Psemini;

    }

    vector<int> findMaxiNse(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> Nsemaxi(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && arr[st.top()]<=arr[i])
            {
                st.pop();
            }
            Nsemaxi[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return Nsemaxi;
        

    }
    vector<int> findMaxiPse(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> Psemaxi(n);
        stack<int> st;

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && arr[st.top()]<arr[i])
            {
                st.pop();
            }
            Psemaxi[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return Psemaxi;

    }

        
    long long sumSubarrayMins(vector<int>& arr) {
        long long total = 0;
        int n = arr.size();

        vector<int> nse =findMiniNse(arr);
        vector<int> pse =findMiniPse(arr);

        int mod  = 1000000007;

        for(int i=0; i<n; i++)
        {
            int left = i-pse[i];
            int right = nse[i]-i;

            total = (total +(right*left*1LL*arr[i]));
        }

        return total;
    }

        
    long long sumSubarrayMaxs(vector<int>& arr) {
        long long total = 0;
        int n = arr.size();

        vector<int> nse =findMaxiNse(arr);
        vector<int> pse =findMaxiPse(arr);

        int mod  = 1000000007;

        for(int i=0; i<n; i++)
        {
            int left = i-pse[i];
            int right = nse[i]-i;

            total = (total +(right*left*1LL*arr[i]));
        }

        return total;

        
    }


    long long subArrayRanges(vector<int>& nums) {


        return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);


        
    }
};