class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10)
        {
            return false;
        }
        int remain = n-10;
        int val = 9;
        bool flag = true;
        while(true)
        {
            if(remain<val)
            {
                return flag;
            }
            else
            {
                remain-=val;
                val = val-1;
                flag = !flag;
            }    
        }
        return true;
    }
};