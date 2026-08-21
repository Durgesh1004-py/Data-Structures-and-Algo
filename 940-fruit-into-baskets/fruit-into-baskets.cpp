class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mpp;
        int start = 0;
        int ans = 0;
        for(int i=0; i<fruits.size(); i++)
        {
            mpp[fruits[i]]++;
            while(mpp.size()>2)
            {
                mpp[fruits[start]]--;
                if(mpp[fruits[start]]==0)
                {
                    mpp.erase(fruits[start]);
                    
                }
                start++;
            }
            ans = max(ans, i-start+1);
        }
        return ans;

    }
};