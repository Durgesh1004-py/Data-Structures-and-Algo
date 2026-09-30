class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> ans;
        ans.push_back(0);
        int cntA = 1;
        int cntB = 0;

        for(int i=1; i<n; i++)
        {
            if(seq[i]=='(')
            {
                if(cntA==cntB)
                {
                    if(ans[i-1]==1)
                    {
                        ans.push_back(0);
                        cntA++;
                    }
                    else
                    {
                        ans.push_back(1);
                        cntB++;
                    }
                }
                else
                {
                    if(cntA>cntB)
                    {
                        ans.push_back(1);
                        cntB++;
                    }
                    else if(cntA<cntB)
                    {
                        ans.push_back(0);
                        cntA++;
                    }
                }
            }
            else
            {
                if(cntA==cntB)
                {
                    ans.push_back(ans[i-1]);
                    if(ans[i-1]==1)
                    {
                        cntB--;
                    }
                    else
                    {
                        cntA--;
                    }
                }
                else
                {
                    if(cntA>cntB)
                    {
                        ans.push_back(0);
                        cntA--;
                    }
                    else if(cntA<cntB)
                    {
                        ans.push_back(1);
                        cntB--;

                    }
                }
            }
            
        }
        return ans;
    }
};