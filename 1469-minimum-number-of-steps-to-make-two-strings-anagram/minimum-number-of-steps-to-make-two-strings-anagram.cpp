class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length();
        unordered_map<char,pair<int,int>> mpp;
        for(int i=0; i<n; i++)
        {
            mpp[s[i]].first++;
        }
        for(int i=0;i<n; i++)
        {
            if(mpp.find(t[i]) != mpp.end())
            {
                mpp[t[i]].second++;
            }
        }
        int cnt = 0;
        for(auto it : mpp)
        {
            if(it.second.first>=it.second.second)
            {
                cnt += (it.second.first-it.second.second);
            }

        }
        return cnt;


        
    }
};