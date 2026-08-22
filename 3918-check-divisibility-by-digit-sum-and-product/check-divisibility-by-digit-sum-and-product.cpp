class Solution {
public:
    bool checkDivisibility(int n) {
        int n1=n;
        int sum = 0;
        int prod = 1;
        while(n)
        {
            sum = sum+(n%10);
            prod = prod*(n%10);
            n = n/10;
        }

        if(n1%(sum+prod)==0)
        {
            return true;
        }
        return false;
        
    }
};