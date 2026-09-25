class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0; i<tokens.size(); i++)
        {
            if(tokens[i]!="+" && tokens[i]!= "-"  && tokens[i]!= "*"  && tokens[i]!= "/" )
            {
                st.push(stoi(tokens[i]));
            }
            else
            {
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                st.pop();

                if(tokens[i]=="+")
                {
                    st.push(t1+t2);
                }
                if(tokens[i]=="-" )
                {
                    st.push(t2-t1);
                }
                if(tokens[i]=="*" )
                {
                    st.push(t1*t2);
                }
                if(tokens[i]=="/" )
                {
                    st.push(t2/t1);
                }
            }
        }
        return st.top();

        
    }
};