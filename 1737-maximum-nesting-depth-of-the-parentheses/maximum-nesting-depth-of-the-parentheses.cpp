class Solution {
public:
    int maxDepth(string s) {
        int opencnt=0;
        int maxcnt=0;
        int ans = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(')
            {
                opencnt+=1;
            }
            else if(s[i]==')')
            {
                ans = maxcnt;
                opencnt-=1;
            }
            else if(s[i]>='0' && s[i]<='9')
            {
                if(maxcnt>=opencnt)
                {
                    ans = maxcnt;
                }
            }
            maxcnt = max(maxcnt, opencnt);
        }
        return ans;
        
    }
};