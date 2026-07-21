class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int>present1(10,0);
        vector<int>present2(10,0);
        for(int i=0;i<9;i++)
        {
            fill(present1.begin(), present1.end(), 0);
            fill(present2.begin(), present2.end(), 0);
            for(int j=0;j<9;j++)
            {
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0';
                    if(present1[num] == 1)
                        return false;
                    present1[num] = 1;
                }

                if(board[j][i] != '.')
                {
                    int num = board[j][i] - '0';
                    if(present2[num] == 1)
                        return false;
                    present2[num] = 1;
                }
            }
        }
        vector<int>present(10,0);
        for(int i=0;i<9;i=i+3)
        {
            for(int j=0;j<9;j=j+3)
            {
                fill(present.begin(), present.end(), 0);
                int starti = i;
                int ni = 3;
                while(ni)
                {
                    int startj = j;
                    int nj = 3;
                    while(nj)
                    {
                        if(board[starti][startj] != '.' )
                        {
                            int num = board[starti][startj] - '0';
                            if(present[num] == 1)
                                return false;
                            present[num] = 1;
                        }
                        nj--;
                        startj++;
                    }
                    starti++;
                    ni--;
                }
                
            }
        }
        return true;

        
    }
};
