class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        string ans = "";
        for(int i=n-1; i>=0; i--)
        {
            char ch = num[i];
            int val = ch - '0';
            if(val%2==1)
            {
                ans = num.substr(0,i+1);
                return ans;
            }
        }
        return ans;
        
    }
};