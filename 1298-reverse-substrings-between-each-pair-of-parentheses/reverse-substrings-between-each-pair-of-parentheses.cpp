class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string ans = "";
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(')
            {
                st.push(ans.size());
            }
            else if(s[i]==')')
            {
                int j = st.top();
                st.pop();
                reverse(ans.begin()+j, ans.end());

            }
            else
            {
                ans = ans+s[i];
            }
        }
        return ans;
         
    }
};
