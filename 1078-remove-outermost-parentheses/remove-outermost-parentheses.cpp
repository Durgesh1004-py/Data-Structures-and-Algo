class Solution {
public:
    string removeOuterParentheses(string s) {
        int cntopen = 0;
        int cntclose = 0;
        string ans = "";
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(')
            {
                cntopen+=1;
            }
            if(cntopen>1 || s[i]==')')
            {
                if(s[i]==')')
                {
                    if(cntopen!=1)
                    {
                        ans +=s[i];
                        cntopen -=1;                        
                    }
                    else
                    {
                        cntopen-=1;
                    }
                }
                else if(s[i]=='(')
                {
                    ans+=s[i];
                }

            }

        }
        return ans;
        
    }
};