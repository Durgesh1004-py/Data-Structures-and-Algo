class Solution {
public:
    bool caneat(vector<int>& piles, int h, int mid)
    {
        int n = piles.size();
        int cnt = h;
     
        for(int i = 0; i < n; i++)
        {
            if(piles[i] % mid == 0)
            {
                cnt -= piles[i] / mid;
            }
            else
            {
                cnt -= (piles[i] / mid + 1);
            }

            if(cnt < 0)       // changed <= to <
            {
                return false;
            }
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = high;

        while(low <= high)    // changed < to <=
        {
            int mid = low + (high - low) / 2;

            if(caneat(piles, h, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};