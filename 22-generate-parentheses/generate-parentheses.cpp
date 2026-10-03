class Solution {
public:
    void parent(int n, vector<string> & ans, string s, int tot, int opencnt)
    {
        if(s.length()==2*n)
        {
            ans.push_back(s);
            return;
        }

        if(tot<n)
        {
            parent(n, ans, s+"(", tot+1, opencnt+1); 
        }

        if(opencnt>0)
        {  
            parent(n, ans, s+")", tot, opencnt-1); 
        }
        

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        parent(n, ans, "", 0, 0);
        return ans;
        
    }
};