class Solution {
public:
    int reverse(int num) {
        double rev = 0;
        bool isneg = false;

        if (num < 0) {
            isneg = true;
            num = -(long long)num; // avoids INT_MIN problem
        }

        while (num > 0) {
            int remainder = num % 10;
            num = num / 10;

            rev = rev * 10 + remainder;
        }

        if (isneg)
            rev = -rev;

        if (rev > INT_MAX || rev < INT_MIN)
            return 0;

        return (int)rev;
    }
};