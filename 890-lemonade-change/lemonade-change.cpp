class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5 = 0;
        int cnt10 = 0;
        int cnt20 = 0;
        for(int i=0; i<bills.size(); i++)
        {
            if(bills[i]==5)
            {
                cnt5++;
            }
            else if(bills[i]==10)
            {
                cnt10++;
                if(cnt5>=1)
                {
                    cnt5--;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                cnt20++;
               
                if(cnt10>=1 && cnt5>=1)
                {
                    cnt5--;
                    cnt10--;
                }
                else if(cnt5>=3)
                {
                    cnt5 -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
        
    }
};