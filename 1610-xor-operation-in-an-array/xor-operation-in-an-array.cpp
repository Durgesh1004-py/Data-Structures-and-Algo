class Solution {
public:
    int xorOperation(int n, int start) {
        int xor1 = 0;
        while(n--)
        {
            xor1 = xor1^start;
            start = start+2;
        }
        return xor1;
        
    }
};