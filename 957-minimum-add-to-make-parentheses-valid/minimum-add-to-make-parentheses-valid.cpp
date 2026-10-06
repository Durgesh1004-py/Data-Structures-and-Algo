class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int cnt=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else
            {
                if(st.empty())
                {
                    cnt+=1;
                }
                else
                {
                    st.pop();
                }
            }
        }

        cnt = cnt + st.size();
        return cnt;
        
    }
};