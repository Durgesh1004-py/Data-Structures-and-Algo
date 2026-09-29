class Solution {
public:
    bool df(vector<vector<char>>& board, int r, int c, int row, int col, int index, string word)
    {
        if(index==word.size()) return true;
        if(r<0 ||c<0 || r>=row || c>=col || board[r][c]!=word[index]) return false;

        char ch = board[r][c];
        board[r][c] = '#';
        ++index;

        bool flag = (df(board, r+1, c,row, col, index, word) ||
         df(board, r, c+1,row, col, index, word) || 
         df(board, r-1, c,row, col, index, word) || 
         df(board, r, c-1,row, col, index, word));

        board[r][c]=ch;
        return flag;

        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        for(int r=0; r<row; r++)
        {
            for(int c=0; c<col; c++)
            {
                if(df(board, r,c,row,col,0, word)) return true;
            }
        }

        return false;
    }
};