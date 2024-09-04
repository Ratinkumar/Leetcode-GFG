class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int nr=board.size();
        int nc=board[0].size();
        int count=0;

        for(int r=0;r<nr;r++)
        {
            for(int c=0;c<nc;c++)
            {
                if(board[r][c]=='X')
                {
                    if((r==0 || board[r-1][c]=='.') && (c==0 || board[r][c-1]=='.'))
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};