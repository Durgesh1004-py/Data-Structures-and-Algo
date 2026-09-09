class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ng = gas.size();
        int cg = gas.size();


        int deficit = 0;
        int balance = 0;
        int startpos = -1;

        for(int i=0; i<ng; i++)
        {
            
            if(balance+gas[i]-cost[i]>=0)
            {
                if(startpos==-1)
                {
                    startpos = i;
                }
                balance = balance + gas[i]-cost[i];
            }
            else
            {
                startpos = -1;
                deficit = deficit + ((cost[i]-gas[i]) - balance);
                balance = 0;
            }

        }

        if(startpos!=-1 && deficit<=balance)
        {
            return startpos;
        }

        return -1;
        
    }
};