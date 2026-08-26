class Solution {
public:
    int getval(char c)
    {
        if(c=='I') return 1;
        if(c=='V') return 5;
        if(c=='X') return 10;
        if(c=='L') return 50;
        if(c=='C') return 100;
        if(c=='D') return 500;
        if(c=='M') return 1000;

        return 0;
    }
    int romanToInt(string s) {
        int i=0;
        int ans=0;
        while(i<s.size()-1)
        {
            if(getval(s[i])>=getval(s[i+1]))
            {
                
                ans = ans+getval(s[i]);
                
            }
            else 
            {
                ans = ans-getval(s[i]);
            }
            i++;
            
        }
        return ans+getval(s[i]);
        
        
    }
};