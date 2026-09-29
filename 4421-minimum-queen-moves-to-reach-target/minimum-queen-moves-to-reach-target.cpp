class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        
        if(source == target)
            return 0;

        int sr = source[0];
        int sc = source[1];

        int tr = target[0];
        int tc = target[1];

        // Same row
        if(sr == tr)
            return 1;

        // Same column
        if(sc == tc)
            return 1;

        // Same diagonal
        if(abs(sr - tr) == abs(sc - tc))
            return 1;

        return 2;
    }
};