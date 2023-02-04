class Solution {
public:
    bool search(vector<vector<char>>& board, string word, int index, int i, int j, int row, int col)
    {
        if(word.length()==index)
            return true;
        if(i<0 || j<0 || i>=row || j>=col)
            return false;
        if(board[i][j]!=word[index])
            return false;
        if(board[i][j]=='-')
            return false;
        char curChar=board[i][j];
        board[i][j]='-';

        bool search_up=search(board,word,index+1,i-1,j,row,col);
        bool search_left=search(board,word,index+1,i,j-1,row,col);
        bool search_down=search(board,word,index+1,i+1,j,row,col);
        bool search_right=search(board,word,index+1,i,j+1,row,col);

        board[i][j]=curChar;
        return search_up || search_left || search_down || search_right;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board.at(0).size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(search(board,word,0,i,j,n,m))
                        return true;
                }
            }
        }
        return false;
    }
};
