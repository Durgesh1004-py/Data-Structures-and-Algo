class Solution {
public:
    bool backspaceCompare(string s, string t) {

        stack<char> st1;
        stack<char> st2;

        for (auto x : s) {

            if (st1.size() > 0 && x == '#') {
                st1.pop();
            }

            if (x != '#') {
                st1.push(x);
            }
        }

        for (auto x : t) {

            if (st2.size() > 0 && x == '#') {
                st2.pop();
            }

            if (x != '#') {
                st2.push(x);
            }
        }

        if (st1.size() != st2.size())
            return false;

        while (st1.size() != 0) {
            if (st1.top() != st2.top())
                return false;
            st1.pop();
            st2.pop();
        }

        return true;
    }
};