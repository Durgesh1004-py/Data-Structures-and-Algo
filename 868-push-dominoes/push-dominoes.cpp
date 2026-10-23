class Solution {
public:
    string pushDominoes(string dominoes) {
        int prev = -1;
        int n = dominoes.size();

        for (int i = 0; i < n; i++) {
            if (dominoes[i] == '.') {
                continue;
            }

            if (prev == -1 && dominoes[i] == 'L') {
                for (int t = 0; t < i; t++) {
                    dominoes[t] = 'L';
                }
            } 
            else if (prev != -1) {
                if (dominoes[prev] == 'R' && dominoes[i] == 'L') {
                    int l = prev + 1;
                    int r = i - 1;

                    while (l < r) {
                        dominoes[l] = 'R';
                        dominoes[r] = 'L';
                        l++;
                        r--;
                    }
                }
                else if (dominoes[prev] == dominoes[i]) {
                    for (int t = prev + 1; t < i; t++) {
                        dominoes[t] = dominoes[prev];
                    }
                }
            }

            prev = i;
        }

        if (prev != -1 && dominoes[prev] == 'R') {
            for (int i = prev + 1; i < n; i++) {
                dominoes[i] = 'R';
            }
        }

        return dominoes;
    }
};